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

const int N = 1005;
const int DIR_X[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int DIR_Y[] = {1, -1, 0, 0, 1, -1, 1, -1};

class Solution {
public:
    bool vis[N][N];
    int cnt;
    int n;
    int m;
    bool check(int x,int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void dfs(vector<vector<int> > & land, int x, int y) {
        if (vis[x][y] == 0) {
            vis[x][y] = 1;
            cnt++;
        }
        for (int i = 0; i < 8; i++) {
            int tmpX = x + DIR_X[i];
            int tmpY = y + DIR_Y[i];
            if (check(tmpX, tmpY) && land[tmpY][tmpY] == 0 && vis[tmpX][tmpY] == 0) {
                dfs(land, tmpX, tmpY);
            }
        }
    }
    vector<int> pondSizes(vector<vector<int> >& land) {
        memset(vis, 0, sizeof(vis));
        vector<int> res;
        this->n = (int)land.size();
        if (n == 0) return res;
        this->m = (int)land[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 0 && vis[i][j] == 0) {
                    cnt = 0;
                    dfs(land, i, j);
                    res.push_back(cnt);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
        
    }
};

int main()
{
    Solution s;

    return 0;
}

