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

const int N = 1e4 * 2 + 5;
const int MOD = 1e9 + 7;
class Solution {
public:
    vector<vector<PII>> adj;
    bool vis[N];
    LL dis[N];
    LL dp[N];

    void spfa(int n)
    {
        queue<int> que;
        que.push(n);
        vis[n] = 1;
        dis[n] = 0;
        while (!que.empty()) {
            int current = que.front();
            que.pop();
            vis[current] = 0;
            int len = (int)adj[current].size();
            for (int i = 0; i < len; i++) {
                int y = adj[current][i].first;
                int w = adj[current][i].second;
                if (dis[y] > dis[current] + w) {
                    dis[y] = dis[current] + w;
                    if (vis[y] == 0) {
                        vis[y] = 1;
                        que.push(y);
                    }
                }
            }
        }
    }
    LL dfs(int idx)
    {
        if (idx == 1) {
            return 1;
        } else {
            if (dp[idx] != -1)
                return dp[idx];

            int len = (int)adj[idx].size();
            dp[idx] = 0;
            for (int i = 0; i < len; i++) {
                int y = adj[idx][i].first;
                if (dis[y] > dis[idx]) {
                    dp[idx] = (dp[idx] + dfs(y)) % MOD;
                }
            }
            cout << "idx:" << idx << " dp:" << dp[idx] << endl;
            return dp[idx];
        }
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges)
    {
        memset(dp, -1, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        memset(dis, 0x3f, sizeof(dis));
        adj.clear();
        adj.resize(n + 1);
        int len = (int)edges.size();
        for (int i = 0; i < len; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            int w = edges[i][2];
            adj[x].push_back(make_pair(y, w));
            adj[y].push_back(make_pair(x, w));
        }

        spfa(n);
        for (int i = 1; i <= n; i++) {
            cout << dis[i] << " ";
        }
        cout << endl;

        dp[1] = 1;
        dfs(n);
        return dp[n];
    }
};

int main()
{
    return 0;
}
