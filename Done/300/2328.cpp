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

const int dirX[] = {0, 0, 1, -1};
const int dirY[] = {1, -1, 0, 0};
const int MOD = 1e9 + 7;

class Solution {
public:
    int n;
    int m;

    bool inRange(int xx, int yy) {
        if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
            return true;
        }
        return false;
    }

    int dfs(int x, int y, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (dp[x][y] != 0) {
            return dp[x][y];
        }

        dp[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int xx = x + dirX[i];
            int yy = y + dirY[i];
            if (inRange(xx, yy) && grid[xx][yy] < grid[x][y]) {
                dp[x][y] = (dp[x][y] + dfs(xx, yy, dp, grid)) % MOD;
            }
        }
        return dp[x][y];
    }

    int countPaths(vector<vector<int>>& grid) {
        this->n = (int)grid.size();
        if (n == 0) {
            return 0;
        }
        this->m = (int)grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == 0) {
                    dfs(i, j, dp, grid);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = (res + dp[i][j]) % MOD;
            }
        }
        return res;
    }
};
int main()
{
    return 0;
}


