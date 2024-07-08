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

const int N = 26;

class Solution {
public:
    int res;
    void dfs(string& s, int k, int lft, int rht)
    {
        // cout << "lft:" << lft << " rht:" << rht << endl;
        vector<int> cnt(N, 0);
        vector<bool> vis(N, 0);
        for (int i = lft; i <= rht; i++) {
            cnt[s[i] - 'a']++;
        }
        bool find = 0;
        for (int i = 0; i < N; i++) {
            if (cnt[i] < k && cnt[i] > 0) {
                vis[i] = 1;
                // cout << "filter out:" << char(i + 'a') << endl;
                find = 1;
            }
        }
        if (find == 0) {
            res = max(res, rht - lft + 1);
        } else {
            int pre = -1;
            int nxt = -1;
            for (int i = lft; i <= rht; i++) {
                if (vis[s[i] - 'a'] == 0) {
                    if (pre == -1) {
                        pre = i;
                        nxt = i;
                    } else {
                        nxt = i;
                    }
                } else {
                    if (pre != -1 && nxt != -1) {
                        dfs(s, k, pre, nxt);
                        pre = -1;
                        nxt = -1;
                    }
                }
            }
            if (pre != -1 && nxt != -1) {
                dfs(s, k, pre, nxt);
                pre = -1;
                nxt = -1;
            }
        }
    }
    int longestSubstring(string s, int k)
    {
        res = 0;
        int len = (int)s.length();
        dfs(s, k, 0, len - 1);
        return res;
    }
};

int main()
{
    Solution s;
    // cout << s.longestSubstring("bbaaacbd", 3) << endl;
    cout << s.longestSubstring("zzzzzzzzzzaaaaaaaaabbbbbbbbhbhbhbhbhbhbhicbcbcibcbccccccccccbbbbbbbbaaaaaaaaafffaahhhhhiaahiiiiiiiiifeeeeeeeeee", 10) << endl;
    return 0;
}
