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

const int N = 155;
const int X[] = {0, 0, 1, -1};
const int Y[] = {1, -1, 0, 0};
class Solution {
public:
    int n;
    int m;
    bool vis[N][N];
    bool flag1;
    bool flag2;
    vector<vector<int> > matrix;
    bool inMatrix(int xx, int yy) {
        return (xx >= 0 && xx < n && yy >= 0 && yy < m);
    }
    bool judge(int xx, int yy, int x, int y) {
        if (inMatrix(xx, yy) && matrix[xx][yy] <= matrix[x][y]) {
            return true;
        }
        return false;
    }
    bool dfs(int x, int y) {
        for (int i = 0; i < 4; i++) {
            int xx = x + X[i];
            int yy = y + Y[i];
            if (inMatrix(xx, yy) && vis[xx][yy]) continue;

            if (xx <= -1 || yy <= -1) {
                flag1 = true;
                if (flag1 && flag2) {
                    return true;
                } else {
                    continue;
                }
            } 

            if (xx >= n || yy >= m) {
                flag2 = true;
                if(flag1 && flag2) {
                    return true;
                } else {
                    continue;
                }
            }

            if (judge(xx, yy, x, y)) {
                vis[xx][yy] = 1;
                if(dfs(xx, yy)) {
                    return true;
                }
            }
        }
        return false;

    }
    vector<vector<int> > pacificAtlantic(vector<vector<int> >& matrix) {
        vector<vector<int> > res;

        this->matrix = matrix;
        this->n = (int)matrix.size();
        if (n == 0) {
            return res;
        }
        this->m = (int)matrix[0].size();

//        cout<<"n:"<<n<<" m:"<<m<<endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                flag1 = 0;
                flag2 = 0;
                memset(vis, 0, sizeof(vis));
                bool flag = dfs(i,j);
//                cout<<"i:"<<i<<" j:"<<j<<" flag:"<<flag<<endl;
                if (dfs(i, j)) {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int> > data;
    int a[] = {3,3,3,3,3,3};
    vector<int> tmp(a, a + sizeof(a) / sizeof(int));
    data.push_back(tmp);
    int a1[] = {3,0,3,3,0,3};
    vector<int> tmp2(a1, a1 + sizeof(a1) / sizeof(int));
    data.push_back(tmp2);
    int a2[] = {3,3,3,3,3,3};
    vector<int> tmp3(a2, a2 + sizeof(a2) / sizeof(int));
    data.push_back(tmp3);

    Solution s;
    s.pacificAtlantic(data);
    return 0;
}

