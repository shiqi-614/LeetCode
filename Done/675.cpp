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

const int N = 55;
const int DIR_X[] = {0, 0, 1, -1};
const int DIR_Y[] = {1, -1, 0, 0};

struct Node {
    int x;
    int y;
    int weight;
    Node(){}
    Node(int x, int y, int weight) : x(x), y(y), weight(weight) {}
    bool operator<(const Node &b) const {
        return weight < b.weight;
    }
};
class Solution {
public:
    int n;
    int m;
    bool vis[N][N];
    int dis[N][N];
    bool judge(int x, int y) {
        if (x >= 0 && x < n && y >= 0 && y < m) {
            return true;
        }
        return false;
    }
    int getDis(int x, int y, int xx, int yy, vector<vector<int> >& forest) {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0x7f, sizeof(dis));

        queue<PII> que;
        que.push(make_pair(x, y));
        vis[x][y] = 1;
        dis[x][y] = 0;

        while(!que.empty()) {
            int currentX = que.front().first;
            int currentY = que.front().second;
            que.pop();
            vis[currentX][currentY] = 0;
            if (currentX == xx && currentY == yy) return dis[currentX][currentY];

            for (int i = 0; i < 4; i++) {
                int nextX = currentX + DIR_X[i];
                int nextY = currentY + DIR_Y[i];
                if (judge(nextX, nextY) && forest[nextX][nextY] != 0 && dis[nextX][nextY] > dis[currentX][currentY] + 1) {
                    dis[nextX][nextY] = dis[currentX][currentY] + 1;
                    if (vis[nextX][nextY] == 0) {
                        vis[nextX][nextY] = 1;
                        que.push(make_pair(nextX, nextY));
                    }
                }
            }

        }
        return -1;

    }
    int cutOffTree(vector<vector<int> >& forest) {
        n = (int)forest.size();
        m = (int)forest[0].size();

        vector<Node> order;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) if (forest[i][j] != 0) {
                order.push_back(Node(i, j, forest[i][j]));
            }
        }

        int res = 0;
        int x = 0;
        int y = 0;
        sort(order.begin(), order.end());
        for (int i = 0; i < (int)order.size(); i++) {
            int tmp = getDis(x, y, order[i].x, order[i].y, forest);
            cout<<x<<" "<<y<<" "<<order[i].x<<" "<<order[i].y<<" "<<tmp<<endl;
            x = order[i].x;
            y = order[i].y;
            if (tmp == -1) {
                return -1;
            }
            res += tmp;
        } 
        return res;
        
    }
};
int main() {

    return 0;
}

