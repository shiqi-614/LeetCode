#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;

const int N =105;

class Solution {
public:
    int dis[N][2];
    bool vis[N][2];
    vector<int> shortestAlternatingPaths(int n, vector<vector<int> >& red_edges, vector<vector<int> >& blue_edges) {
        memset(dis, 0x7f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        vector<vector<int> > blue(n);
        vector<vector<int> > red(n);

        for (int i = 0; i < (int)blue_edges.size(); i++) {
            int x = blue_edges[i][0];
            int y = blue_edges[i][1];
            blue[x].push_back(y);
        }

        for (int i = 0; i < (int)red_edges.size(); i++) {
            int x = red_edges[i][0];
            int y = red_edges[i][1];
            red[x].push_back(y);
        }

        vector<vector<vector<int> > > edges;
        edges.push_back(blue);
        edges.push_back(red);


        queue<PII> que;
        que.push(make_pair(0, 0));
        que.push(make_pair(0, 1));
        vis[0][0] = 1;
        vis[0][1] = 1;
        dis[0][0] = 0;
        dis[0][1] = 0;
        
        while(!que.empty()) {
            int index = que.front().first;
            int type  = que.front().second;
            que.pop();

            cout<<index<<" "<<type<<endl;

            vis[index][type] = 0;
            for (int i = 0; i < (int)edges[type^1][index].size(); i++) {
                int to = edges[type^1][index][i];
                if (dis[to][type^1] > dis[index][type] + 1) {
                    dis[to][type^1] = dis[index][type] + 1;
                    if (!vis[to][type^1]) {
                        vis[to][type^1] = 1;
                        que.push(make_pair(to, type^1));
                    }
                }
            }
        }
        
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int mi = min(dis[i][0], dis[i][1]);
            if (mi < N * N) {
                res.push_back(mi);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};

int main() {

    return 0;
}

