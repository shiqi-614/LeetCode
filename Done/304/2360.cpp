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

const int N = 1e5+5;
class Solution {
public:
    bool vis[N];
    int fa[N];
    int res;
    bool dfs(vector<int>& edges, int cur, int target, int depth) {
        // cout<<"cur:"<<cur<<" targe:"<<target<<endl;
        if (target == cur) {
            res = max(res, depth);
            return true;
        }

        vis[cur] = 1;
        int to = edges[cur];
        if (vis[to] == 0) {
            if (dfs(edges, to, target, depth + 1)) {
                // cout<<"cur:"<<cur<<" to:"<<to<<endl;
                return true;
            }
        }
        return false;
    }

    int find_fa(int x) {
        if (fa[x] != x) return fa[x] = find_fa(fa[x]);
        return fa[x];
    }

    void unin(int x, int y) {
        fa[x] = y;
    }

    int longestCycle(vector<int>& edges) {
        res = -1;
        int len = (int)edges.size();

        for (int i = 0; i < len; i++) {
            fa[i] = i; 
        }

        for (int i = 0; i < len; i++) {
            int from = i;
            int to = edges[i];
            if (to != -1) {
                if (find_fa(from) != find_fa(to)) {
                    unin(from, to);
                } else {
                    memset(vis, 0, sizeof(vis));
                    // cout<<"find:"<<to<<" "<<from<<endl;
                    dfs(edges, to, from, 1);
                }
            }
        }
        return res;
    }
};

int main()
{

    freopen("2360.in", "r", stdin);
    int n;
    int m;

    scanf("%d\n", &n);
    Solution s;
    for (int i = 0;i < n; i++) {
        scanf("%d ", &m);
        vector<int> data;
        for (int j = 0; j < m; j++) {
            int tmp;
            scanf("%d", &tmp);
            data.push_back(tmp);
        }
        cout<<s.longestCycle(data)<<endl;
    }
    return 0;
}


