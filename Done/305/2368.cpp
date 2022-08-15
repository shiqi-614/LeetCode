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

const int N = 1e5 + 5;

class Solution {
public:
    bool vis[N];
    set<int> restrict;
    vector<vector<int>> adj;
    void dfs(int cur) {
        vis[cur] = 1;
        for (int i = 0; i <(int)adj[cur].size(); i++) {
            int nxt = adj[cur][i];
            if (vis[nxt] == 0 && restrict.find(nxt) == restrict.end()) {
                dfs(nxt);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        restrict.clear();
        memset(vis, 0, sizeof(vis));
        adj.clear();
        adj.resize(n, vector<int>());
        for (int i = 0; i < (int)restricted.size(); i++) {
            restrict.insert(restricted[i]);
        }

        for (int i = 0; i < (int)edges.size(); i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(0);

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}


