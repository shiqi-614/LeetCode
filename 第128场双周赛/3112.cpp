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

typedef pair<int, int> PII;
typedef long long LL;

const LL INF = (1 << 60);

struct Edge {
    int v;
    int w;
    Edge() { }
    Edge(int v, int w)
        : v(v)
        , w(w)
    {
    }
    bool operator<(const Edge& e) const
    {
        return w < e.w;
    }
};
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear)
    {
        vector<LL> dis(n, INF);
        vector<bool> vis(n, 0);
        vector<vector<Edge>> adj(n, vector<Edge>());
        int len = (int)edges.size();
        map<PII, int> H;
        for (int i = 0; i < len; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if (u > v) {
                swap(u, v);
            }
            PII pi = MP(u, v);
            if (H.find(pi) == H.end()) {
                H[MP(u, v)] = w;
            } else if (H[pi] > w) {
                H[pi] = w;
            }
        }
        for (map<PII, int>::iterator it = H.begin(); it != H.end(); it++) {
            PII pi = it->first;
            int u = pi.first;
            int v = pi.second;
            int w = it->second;
            adj[u].push_back(Edge(v, w));
            adj[v].push_back(Edge(u, w));
        }
        for (int i = 0; i < n; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        queue<int> que;
        que.push(0);
        vis[0] = 1;
        dis[0] = 0;
        while (!que.empty()) {
            int top = que.front();
            que.pop();
            vis[top] = 0;
            len = (int)adj[top].size();
            for (int i = 0; i < len; i++) {
                int v = adj[top][i].v;
                int w = adj[top][i].w;
                LL tmp = dis[top] + w;
                if (tmp < dis[v] && tmp < disappear[v]) {
                    dis[v] = tmp;
                    if (!vis[v]) {
                        vis[v] = 1;
                        que.push(v);
                    }
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (dis[i] == INF) {
                res.push_back(-1);
            } else {
                res.push_back((int)dis[i]);
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
