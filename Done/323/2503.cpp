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
const int N = 1e3 + 5;
struct Node {
    int query;
    int idx;
    Node(){}
    Node(int query,int idx) : query(query), idx(idx) {}
    bool operator<(const Node& node) const {
        return query < node.query;
    }
};
const int dir_x[] = {0,0,1,-1};
const int dir_y[] = {1,-1,0,0};
class Solution {
public:
    int n;
    int m;
    bool vis[N][N];
    vector<Node> order;
    int getIdx(int value, vector<int>& queries) {
        int idx = upper_bound(queries.begin(), queries.end(), value) - queries.begin();
        if (idx >= 0 && idx < (int)queries.size()) {
            return idx;
        }
        return -1;
    }
    bool check(int x, int y) {
        return x >= 0 && x < n && y >=0 && y < m;
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        this->n = (int)grid.size();
        this->m = (int)grid[0].size();
        int len = (int)queries.size();
        memset(vis, 0, sizeof(vis));
        order.clear();

        for (int i = 0; i < len; i++) {
            order.push_back(Node(queries[i], i));
        }
        sort(order.begin(), order.end());
        sort(queries.begin(), queries.end());
 
        vector<queue<PII>> queList(len, queue<PII>());
        vector<int> res(len, 0);

        int idx = getIdx(grid[0][0], queries);
        if (idx != -1) {
            queList[idx].push(make_pair(0, 0));
            res[order[idx].idx]++;
            vis[0][0]=1;
        }
        

        for (int i = 0; i < len; i++) {
            while(!queList[i].empty()) {
                PII top = queList[i].front(); queList[i].pop();
                for (int j = 0; j < 4; j++) {
                    int x = top.first + dir_x[j];
                    int y = top.second+ dir_y[j];
                    if (!check(x, y)) continue;
                    if (vis[x][y]) continue;
                    
                    if (grid[x][y] < order[i].query) {
                        queList[i].push(make_pair(x, y));
                        res[order[i].idx]++;
                    } else {
                        idx = getIdx(grid[x][y], queries);
                        if (idx != -1) {
                            queList[idx].push(make_pair(x, y));
                            res[order[idx].idx]++;
                            
                        }
                    }
                    vis[x][y]=1;
                }
            }
        }
        
        for (int i = 1; i < len; i++) {
            res[order[i].idx] += res[order[i-1].idx];
        }
        
        return res;
    }
};

int main() {
    return 0;
}
