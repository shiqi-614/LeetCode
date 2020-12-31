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

const int N = 14;
class Solution {
public:
    int dp[N][N];
    int tilingRectangle(int n, int m) {
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; i <= m; j++) {
                if (i == j) dp[i][j] = 1;
                if (i == 1 || j == 1) dp[i][j] = max(i, j);

                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
                }
                
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j]);
                }

            }
        }
        return dp[n][m];
    }
};
int main()
{
    return 0;
}

