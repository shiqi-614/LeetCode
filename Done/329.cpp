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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int dirX[] = {0, 0, 1, -1};
const int dirY[] = {1, -1, 0, 0};
class Solution {
public:
    int n;
    int m;

    bool check(int x, int y) {
        if (x >= 0 && x < n && y >= 0 && y < m) return true;
        return false;
    }
    void spfa(int beginX, int beginY, vector<vector<int> >& res, vector<vector<bool> >& vis, vector<vector<int> >& matrix) {
        queue<PII> que;
        que.push(MP(beginX, beginY));
        vis[beginX][beginY] = 1;

        while(!que.empty()) {
            int x = que.front().first; 
            int y = que.front().second;
            que.pop();

            vis[x][y] = 0;

            for (int i = 0; i < 4; i++) {
                int nextX = x + dirX[i];
                int nextY = y + dirY[i];
                if (check(nextX, nextY) && matrix[x][y] > matrix[nextX][nextY]) {
                    if (res[nextX][nextY] < res[x][y] + 1) {
                        res[nextX][nextY] = res[x][y] + 1;
                        if (vis[nextX][nextY] == 0) {
                            vis[nextX][nextY] = 1;
                            que.push(MP(nextX, nextY));
                        }
                    }
                }
            }
            
        }
    }
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        this->n = (int)matrix.size();
        if (n == 0) return 0;
        this->m = (int)matrix[0].size();
        if (n == 0 || m == 0) return 0;

        vector<vector<int> > res(n, vector<int>(m, 0));
        vector<vector<bool> > vis(n, vector<bool>(m, 0));


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                spfa(i, j, res, vis, matrix);
            }
        }

        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mx = max(mx, res[i][j]);
            }
        }
        return mx + 1;
    }

};

int main()
{
    return 0;
}

