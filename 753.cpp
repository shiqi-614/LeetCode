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

typedef long long LL;
typedef pair<int, int> PII;

class Solution {
public:
    map<string, bool> H;
    string res;
    void generate(string str, int n, int k)
    {
        if (str.length() == n) {
            // cout << "str:" << str << endl;
            H[str] = 0;
            return;
        } else {
            for (int i = 0; i < k; i++) {
                generate(str + (char)('0' + i), n, k);
            }
        }
    }
    void dfs(string str, int n, int k, int cnt)
    {
        // cout << "dfs:" << str << " cnt:" << cnt << endl;
        if (cnt == (int)H.size()) {
            // cout << "res:" << str << endl;
            res = str;
            return;
        }
        if (res.size() > 0) {
            return;
        }
        if (str.size() >= n) {
            int len = (int)str.length();
            string prefix = str.substr(len - n + 1);
            for (int i = 0; i < k; i++) {
                string tmp = prefix + char('0' + i);
                if (H[tmp] == 0) {
                    H[tmp] = 1;
                    // cout << "find:" << str << endl;
                    dfs(str + char('0' + i), n, k, cnt + 1);
                    H[tmp] = 0;
                }
            }

        } else {
            for (int i = 0; i < k; i++) {
                string tmp = str + char('0' + i);
                if (tmp.size() == n) {
                    H[tmp] = 1;
                    dfs(tmp, n, k, 1);
                    H[tmp] = 0;
                } else {
                    dfs(tmp, n, k, 0);
                }
            }
        }
    }
    string crackSafe(int n, int k)
    {
        generate("", n, k);
        dfs("", n, k, 0);
        return res;
    }
};

int main()
{
    Solution s;
    cout << "res:" << s.crackSafe(2, 2) << endl;
    return 0;
}
