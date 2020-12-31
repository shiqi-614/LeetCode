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

const int N = 105;
const int DIR_X[] = {0, 0, 1, -1};
const int DIR_Y[] = {1, -1, 0, 0};

class Solution {
public:
    int n;
    int m;
    int adj[N][N][4];
    bool vis[N][N];
    int dis[N][N];
    int spfa() {
        queue<PII> que;
        que.push(MP(0, 0));
        vis[0][0] = 1;
        dis[0][0] = 0;

        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            vis[x][y] = 0;

            for (int i = 0; i < 4; i++) {
                int nextX = x + DIR_X[i];
                int nextY = y + DIR_Y[i];
                if (nextX >= n || nextX < 0 || nextY >= m || nextY < 0) continue;
                if (dis[nextX][nextY] > dis[x][y] + adj[x][y][i]) {
                    dis[nextX][nextY] = dis[x][y] + adj[x][y][i];
                    if (vis[nextX][nextY] == 0) {
                        vis[nextX][nextY] = 1;
                        que.push(MP(nextX, nextY));
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
    int minCost(vector<vector<int> >& grid) {
        n = (int)grid.size();
        if (n == 0) return 0;
        m = (int)grid[0].size();

        memset(adj, -1, sizeof(adj));
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                adj[i][j][0] = 1;
                adj[i][j][1] = 1;
                adj[i][j][2] = 1;
                adj[i][j][3] = 1;
                int tmp = grid[i][j] - 1;
                adj[i][j][tmp] = 0;
            }
        }
        return spfa();

    }
};

int main() {
    int tmp1[] = {1,1,1,1};
    vector<int> data1(tmp1, tmp1 + sizeof(tmp1) / sizeof(int));
    int tmp2[] = {2,2,2,2};
    vector<int> data2(tmp2, tmp2 + sizeof(tmp2) / sizeof(int));
    int tmp3[] = {1,1,1,1};
    vector<int> data3(tmp3, tmp3 + sizeof(tmp3) / sizeof(int));
    int tmp4[] = {2,2,2,2};
    vector<int> data4(tmp4, tmp4 + sizeof(tmp4) / sizeof(int));

    vector<vector<int> > data;
    data.PB(data1);
    data.PB(data2);
    data.PB(data3);
    data.PB(data4);

//    int tmp1[] = {1,2};
//    vector<int> data1(tmp1, tmp1 + sizeof(tmp1) / sizeof(int));
//    int tmp2[] = {4,3};
//    vector<int> data2(tmp2, tmp2 + sizeof(tmp2) / sizeof(int));
//
//    vector<vector<int> > data;
//    data.PB(data1);
//    data.PB(data2);


    Solution s;
    cout<<s.minCost(data)<<endl;
    return 0;
}

