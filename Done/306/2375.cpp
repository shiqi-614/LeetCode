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
    bool vis[10];
    bool dfs(int idx, string& pattern, string& res) {
        if (idx == (int)pattern.size()) {
            // cout<<"end:"<<res<<" idx:"<<idx<<endl;
            return true;
        } else {
            for (char i = '1'; i <= '9'; i++) {
                if (vis[i - '1'] == 0) {
                    if (pattern[idx] == 'I') {
                        if (i > res[idx]) {
                            res[idx + 1] = i;
                            vis[i - '1'] = 1;
                            if (dfs(idx + 1, pattern, res)) {
                                return true;
                            }
                            res[idx + 1] = ' ';
                            vis[i - '1'] = 0;

                        }
                    } else {
                        if (i < res[idx]) {
                            res[idx + 1] = i;
                            vis[i - '1'] = 1;
                            if (dfs(idx + 1, pattern, res)) {
                                return true;
                            }
                            res[idx + 1] = ' ';
                            vis[i - '1'] = 0;
                        }
                    }
                }
            }
            return false;
        }
    }
    string smallestNumber(string pattern) {
        int len = (int)pattern.length();
        for(char i = '1'; i <= '9'; i++) {
            string res(len + 1, ' ');
            memset(vis, 0, sizeof(vis));
            res[0] = i;
            vis[i - '1'] = 1;
            if (dfs(0, pattern, res)) {
                return res;
            }
            vis[i - '1'] = 0;
        }
        return "";
    }
};



int main()
{
    Solution s;
    cout<<s.smallestNumber("IIIDIDDD")<<endl;
    cout<<s.smallestNumber("DDD")<<endl;
    cout<<s.smallestNumber("DDDDDDDD")<<endl;
    return 0;
}


