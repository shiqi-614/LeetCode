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

typedef long long LL;
typedef pair<int, int> PII;

const int N = 505;
class Solution {
public:
    int dp[N][N * 2];
    int paintWalls(vector<int>& cost, vector<int>& time)
    {
        int len = (int)cost.size();

        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        int res = 1 << 30;
        for (int idx = 0; idx < len; idx++) {
            int c = cost[idx];
            int t = time[idx];
            for (int i = idx; i >= 0; i--) {
                for (int j = 0; j < N; j++) {
                    if (dp[i][j] >= res)
                        continue;
                    if (dp[i][j] != -1 && j + t + i + 1 < len * 2) {
                        if (dp[i + 1][j + t] == -1) {
                            dp[i + 1][j + t] = c + dp[i][j];
                        } else {
                            dp[i + 1][j + t] = min(c + dp[i][j], dp[i + 1][j + t]);
                        }
                        if (j + t + i + 1 >= len) {
                            // cout << "i:" << i << " j:" << j << " t:" << t << endl;
                            // cout << "i + 1:" << i + 1 << " j + t:" << j + t << " res:" << dp[i + 1][j + t] << endl;
                            res = min(res, dp[i + 1][j + t]);
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
