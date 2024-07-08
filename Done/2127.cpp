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
    int maximumInvitations(vector<int>& favorite)
    {
        int len = (int)favorite.size();
        vector<int> cnt(len, 0);
        for (int i = 0; i < len; i++) {
            cnt[favorite[i]]++;
        }
        queue<int> que;
        vector<int> dp(len, 1);
        vector<bool> vis(len, 0);
        for (int i = 0; i < len; i++) {
            if (cnt[i] == 0) {
                que.push(i);
                vis[i] = 1;
            }
        }

        while (!que.empty()) {
            int u = que.front();
            que.pop();
            int v = favorite[u];
            cnt[v]--;
            dp[v] = max(dp[v], dp[u] + 1);

            if (cnt[v] == 0) {
                if (vis[v] == 0) {
                    vis[v] = 1;
                    que.push(v);
                }
            }
        }

        int mx = 0;
        int tot = 0;
        for (int i = 0; i < len; i++) {
            if (vis[i] == 0) {
                int tmp = favorite[i];
                if (i == favorite[tmp]) {
                    tot += dp[tmp] + dp[i];
                    vis[i] = 1;
                    vis[tmp] = 1;
                } else {
                    int u = i;
                    int loop = 1;
                    vis[u] = 1;
                    while (favorite[u] != i) {
                        // cout<<"u:"<<u<<" favorite:"<<favorite[u]<<endl;
                        u = favorite[u];
                        loop++;
                        vis[u] = 1;
                        // cout<<"loop:"<<loop<<endl;
                    }
                    mx = max(mx, loop);
                }
            }
        }
        return max(mx, tot);
    }
};

int main()
{
    return 0;
}
