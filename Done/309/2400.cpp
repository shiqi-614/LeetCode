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

const int MOD = 1e9 + 7;
const int N = 1005;

class Solution {
public:
    int dp[N][N];
    int dfs(int cur, int end, int k) {
        if (k == 0) {
            if (cur == end) {
                return 1;
            } else {
                return 0;
            }
        } else {
            int& res = dp[cur][k];
            if (res != -1) {
                return res;
            }
            res = 0;
            if (cur - 1 >= 0) {
                res = (res + dfs(cur - 1, end, k -1)) % MOD;
            } else {
                res = (res + dfs(cur + 1, end, k -1)) % MOD;
            }
            return res;
        }

    }     
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof(dp));
        return dfs(startPos, endPos, k);
    }
};

int main()
{
    return 0;
}


