#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

class Solution {
public:
    int n;
    int dfs(vector<int>& odd, vector<int>& cnt, map<PII, bool>& H) {
        bool find = false;
        int len = (int)odd.size();
        for (int i = 0; i < len; i++) {
            if (cnt[odd[i]] % 2 == 1) {
                find = true;
            }
        }
        if (find == false) return 0;

        int res = n;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int a = odd[i];
                int b = odd[j];
                PII pii = make_pair(a, b);
                if (cnt[a]%2 ==1 && cnt[b] % 2 == 1) {
                    if (H.find(pii) == H.end()) {
                        H.insert(make_pair(pii, true));
                        cnt[a]++;
                        cnt[b]++;
                        cout<<"add:"<<a<<" "<<b<<endl;
                        res = min(res, dfs(odd, cnt, H) + 1);
                        cout<<"remove:"<<a<<" "<<b<<endl;
                        cnt[a]--;
                        cnt[b]--;
                        H.erase(pii);

                    } else {
                        for (int k = 1; k <= n; k++) {
                            if (k == a || k == b) continue;
                            PII pii1 = make_pair(min(a, k), max(a, k));
                            PII pii2 = make_pair(min(b, k), max(b, k));
                            if (H.find(pii1) == H.end() && H.find(pii2) == H.end()) {
                                cout<<"add2:"<<a<<" "<<b<<" "<<endl;
                                cnt[a]++;
                                cnt[b]++;
                                H.insert(make_pair(pii1, true));
                                H.insert(make_pair(pii2, true));
                                res = min(res, dfs(odd, cnt, H) + 2);
                                cout<<"remove2:"<<a<<" "<<b<<" "<<endl;
                                cnt[a]--;
                                cnt[b]--;
                                H.erase(pii1);
                                H.erase(pii2);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }

    bool isPossible(int n, vector<vector<int>>& edges) {
        this->n = n;
        vector<int>cnt(n + 1, 0);
        map<PII, bool> H;
        int len = (int)edges.size();
        for (int i = 0; i < len; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            if (a > b) swap(a, b);
            cnt[a]++;
            cnt[b]++;
            PII pii = make_pair(a, b);
            H.insert(make_pair(pii, true));
        }

        vector<int> odd;
        for (int i = 0; i <= n; i++) {
            if (cnt[i] % 2 == 1) {
                odd.push_back(i);
                // cout<<"odd:"<<i<<endl;
            }
        }
        // cout<<"end"<<endl;
        if (odd.size() > 4) {
            return false;
        }
        if (odd.size() % 2) {
            return false;
        }
        if (odd.size() == 0) {
            return true;
        }
        int res = dfs(odd, cnt, H);
        cout<<"dfs res:"<<res<<endl;
        if(res >= 2) {
            return false;
        } else {
            return true;
        }

        return true;
    }
};

int main()
{
    return 0;
}


