#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;

const int N = 11;
class Solution {
public:
    int dp[N][N][3];
    vector<int> digs;
    void toVector(int n) {
        string s;
        while(n) {
            int tmp = n % 10;
            n/=10;
            digs.push_back(tmp);
        }
        reverse(digs.begin(), digs.end());
    }

    int dfs(int idx, int value, int type) {
        // type 0, smaller
        // type 1, equal
        // type 2, bigger
        if (idx == (int)digs.size() - 1) {
            if (type == 2) {
                if (value == 10) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
//                cout<<"idx:"<<idx<<" value:"<<value<<endl;
                return 1;
            }
        } else if (value == 10) {
//            cout<<"idx:"<<idx<<" value:"<<value<<endl;
            return 1;
        } else {
            int &res = dp[idx][value][type];
            if (res != -1) {
                return res;
            } else {
                res = 0;
                if (type == 0) {
                    for (int i = 0; i <= 9; i++) {
                        res += dfs(idx + 1, i, 0);
                    } 
                } else if (type == 1) {
                    for (int i = 0; i < digs[idx + 1]; i++) {
                        res += dfs(idx + 1, i, 0);
                    }
                    res += dfs(idx + 1, digs[idx], 1);
                } else {
                    for (int i = 0; i <= 10; i++) {
                        res += dfs(idx + 1, i, 2);
                    }
                }
                return res;
            }
        }
    }

    bool checkAndUpdate(int cnt, int& remain, int& res, int cur) {
//        cout<<"cnt:"<<cnt<<" remain:"<<remain<<" res:"<<res<<" cur:"<<cur<<endl;
        if (cnt < remain) {
            remain -= cnt;
            return false;
        } else {
            if (cur != 10) {
                res = res * 10 + cur;
            }
            return true;
        }
    }


    int findKthNumber(int n, int k) {
        this->digs.clear();
        memset(dp, -1, sizeof(dp));

        toVector(n);
        int res = 0;
        int type = -1;
        for (int i = 0; i < (int)digs.size() && k; i++) {
            if (i == 0) {
                for (int cur = 1; cur <= 9; cur++) {
                    int cnt = 0;
                    if (cur > digs[0]) {
                        type = 2;
                        cnt += dfs(0, cur, type);
                    }
                    else if (cur == digs[0]) {
                        type = 1;
                        cnt += dfs(0, cur, type) + dfs(0, cur, 2);
                    }
                    else {
                        type = 0;
                        cnt += dfs(0, cur, type) + dfs(0, cur, 2);
                    }

                    if (checkAndUpdate(cnt, k, res, cur)) {
                        break;
                    }
                }
            } else {
                if (checkAndUpdate(dfs(i, 10, type), k, res, 10)) {
                    continue;
                }
                if (type == 0) {
                    for (int cur = 0; cur <= 9; cur++) {
                        if (checkAndUpdate(dfs(i, cur, type) + dfs(i, cur, 2), k, res, cur)) {
                            break;
                        }
                    }
                } else if (type == 1) {
                    for (int cur = 0; cur <= 9; cur++) {
                        if (cur < digs[i]) {
                            if (checkAndUpdate(dfs(i, cur, 0) + dfs(i, cur, 2), k, res, cur)) {
                                type = 0;
                                break;
                            }
                        } else if (cur == digs[i]) {
                            if (checkAndUpdate(dfs(i, cur, 1) + dfs(i, cur, 2), k, res, cur)) {
                                break;
                            }
                        } else {
                            if (checkAndUpdate(dfs(i, cur, 2), k, res, cur)) {
                                type = 2;
                                break;
                            }
                        }
                    }
                } else {
                    for (int cur = 0; cur <= 9; cur++) {
                        if (checkAndUpdate(dfs(i, cur, 2), k, res, cur)) {
                            break;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};

int main() {
    Solution s;
    for (int i = 1; i <= 100; i++) {
        cout<<s.findKthNumber(100, i)<<endl;
    }
//        cout<<s.findKthNumber(100, 4)<<endl;
    return 0;
}

