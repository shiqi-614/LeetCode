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

struct Edge {
    int x;
    int y;
    int dis;
    Edge() { }
    Edge(int x, int y, int dis)
        : x(x)
        , y(y)
        , dis(dis)
    {
    }
};
struct Node {
    int x;
    int y;
    int state;
    Node() { }
    Node(int x, int y, int state)
        : x(x)
        , y(y)
        , state(state)
    {
    }
};
const int N = 35;
const int M = 65;
const int dir_x[] = { 1, -1, 0, 0 };
const int dir_y[] = { 0, 0, -1, 1 };
class Solution {
public:
    int n;
    int m;
    int finalState;
    map<PII, vector<Edge>> edges;
    bool vis[N][N][M];
    int dis[N][N][M];
    bool isKey(char chr)
    {
        return chr >= 'a' && chr <= 'z';
    }
    bool isLock(char chr)
    {
        return chr >= 'A' && chr <= 'Z';
    }
    bool checkState(int state, char chr)
    {
        int idx = chr - 'A';
        return (state & (1 << idx)) > 0;
    }
    bool check(int xx, int yy, vector<string>& grid, char chr)
    {
        bool flag = (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] != '#');

        return flag;
    }
    void getEdge(vector<string>& grid, int x, int y)
    {
        int matrix[N][N];
        memset(matrix, 0x3f, sizeof(matrix));
        queue<PII> que;
        que.push(make_pair(x, y));
        matrix[x][y] = 0;
        while (!que.empty()) {
            PII top = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int xx = top.first + dir_x[i];
                int yy = top.second + dir_y[i];
                if (check(xx, yy, grid, grid[x][y]) && matrix[xx][yy] > matrix[top.first][top.second] + 1) {
                    matrix[xx][yy] = matrix[top.first][top.second] + 1;
                    if (!isLock(grid[xx][yy])) {
                        que.push(make_pair(xx, yy));
                    }
                }
            }
        }
        PII now = make_pair(x, y);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.' || grid[i][j] == '#') {
                    continue;
                }
                if (matrix[i][j] <= n * m && matrix[i][j] > 0) {
                    if (edges.find(now) == edges.end()) {
                        edges[now] = vector<Edge>();
                    }
                    //cout << "st:" << x << ", y:" << y << " -> i:" << i << ",j:" << j << " dis:" << matrix[i][j] << endl;
                    edges[now].push_back(Edge(i, j, matrix[i][j]));
                }
            }
        }
    }
    int shortestPathAllKeys(vector<string>& grid)
    {
        n = (int)grid.size();
        if (n <= 0) {
            return 0;
        }
        m = (int)grid[0].length();
        finalState = 0;
        memset(vis, 0, sizeof(vis));
        memset(dis, 0x3f, sizeof(dis));
        edges.clear();

        Node st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.' || grid[i][j] == '#') {
                    continue;
                } else {
                    getEdge(grid, i, j);
                    if (grid[i][j] == '@') {
                        st = Node(i, j, 0);
                    } else if (isKey(grid[i][j])) {
                        finalState |= (1 << (grid[i][j] - 'a'));
                    }
                }
            }
        }

        queue<Node> que;
        que.push(st);
        dis[st.x][st.y][0] = 0;
        while (!que.empty()) {
            Node current = que.front();
            que.pop();
            vis[current.x][current.y][current.state] = 0;
            PII pos = make_pair(current.x, current.y);
            for (int i = 0; i < (int)edges[pos].size(); i++) {
                Edge edge = edges[pos][i];
                int x = edge.x;
                int y = edge.y;
                if (isKey(grid[x][y])) {
                    Node nxt = Node(x, y, current.state | (1 << (grid[x][y] - 'a')));
                    if (dis[nxt.x][nxt.y][nxt.state] > dis[current.x][current.y][current.state] + edge.dis) {
                        dis[nxt.x][nxt.y][nxt.state] = dis[current.x][current.y][current.state] + edge.dis;
                        if (vis[nxt.x][nxt.y][nxt.state] == 0) {
                            vis[nxt.x][nxt.y][nxt.state] = 1;
                            que.push(nxt);
                        }
                    }
                } else if (isLock(grid[x][y]) && checkState(current.state, grid[x][y])) {
                    Node nxt = Node(x, y, current.state);
                    if (dis[nxt.x][nxt.y][nxt.state] > dis[current.x][current.y][current.state] + edge.dis) {
                        dis[nxt.x][nxt.y][nxt.state] = dis[current.x][current.y][current.state] + edge.dis;
                        if (vis[nxt.x][nxt.y][nxt.state] == 0) {
                            vis[nxt.x][nxt.y][nxt.state] = 1;
                            que.push(nxt);
                        }
                    }
                }
            }
        }
        int res = N * N;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = min(res, dis[i][j][finalState]);
            }
        }
        if (res == N * N)
            return -1;
        return res;
    }
};

int main()
{
    vector<string> data;
    //string tmp[] = { "@.a.#", "###.#", "b.A.B" };
    //string tmp[] = { "@..aA", "..B#.", "....b" };
    string tmp[] = { "@abcdeABCDEFf" };
    for (int i = 0; i < 1; i++) {
        data.push_back(tmp[i]);
    }
    Solution s;
    cout << s.shortestPathAllKeys(data) << endl;
    return 0;
}
