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

const int N = 1e5 + 5;

class Solution {
public:
    int vis[N];
    int rt[N];
    int cnt[N];
    int mx = -1;
    void dfs(int idx, int dep, vector<int>& adj, int root)
    {
        vis[idx] = dep;
        rt[idx] = root;
        if (adj[idx] != -1) {
            int nxt = adj[idx];
            if (vis[nxt] == 0) {
                dfs(nxt, dep + 1, adj, root);
            } else {
                if (vis[nxt] < dep + 1 && rt[nxt] == rt[idx]) {
                    mx = max(mx, abs(dep + 1 - vis[nxt]));
                }
            }
        }
    }
    int longestCycle(vector<int>& edges)
    {
        int len = (int)edges.size();
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        memset(rt, -1, sizeof(rt));
        for (int i = 0; i < len; i++) {
            if (edges[i] != -1) {
                cnt[edges[i]]++;
            }
        }
        for (int i = 0; i < len; i++) {
            if (cnt[i] == 0) {
                dfs(i, 1, edges, i);
            }
        }

        for (int i = 0; i < len; i++) {
            if (vis[i] == 0) {
                dfs(i, 1, edges, i);
            }
        }
        return mx;
    }
};

int main()
{
    return 0;
}
