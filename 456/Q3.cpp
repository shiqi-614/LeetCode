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

typedef pair<int, int> PII;
typedef long long LL;

#define INF (1<<30)
const int N = 251;
class Solution {
    public:
        int dp[N][N];
        int xorSum[N][N];
        int dfs(int len, int k) {
            if (k == 0) {
                if (len == -1) {
                    return 0;
                } else {
                    return INF;
                }
            }
            if (len < 0) {
                return INF;
            }

            if (dp[len][k] != -1) {
                return dp[len][k];
            }

            dp[len][k] = INF;
            for (int i = len; i >= 0; i--) {
                dp[len][k] = min(dp[len][k], max(xorSum[i][len], dfs(i - 1, k - 1)));
            }
            return dp[len][k];
        }

        int minXor(vector<int>& nums, int k) {
            memset(dp, -1, sizeof(dp));
            memset(xorSum, 0, sizeof(xorSum));

            int len = (int)nums.size();
            for (int i = 0; i < len; i++) {
                int cur = 0;
                for (int j = i; j < len; j++) {
                    cur = cur ^ nums[j];
                    xorSum[i][j] = cur;
                }
            }

            return dfs(len - 1, k);
        }
};

int main()
{
    return 0;
}

