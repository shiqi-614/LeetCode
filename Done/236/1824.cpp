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

const int N = 5e5 + 10;
int dp[N][3];

class Solution {
public:
    int minSideJumps(vector<int>& obstacles)
    {
        int len = (int)obstacles.size();
        memset(dp, 0x3f, sizeof(dp));
        dp[0][1] = 0;

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] != j + 1) {
                    if (i > 0) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                    }
                }
                for (int j = 0; j < 3; j++) {
                    if (obstacles[i] != j + 1) {
                        dp[i][j] = min(dp[i][j], dp[i][0] + 1);
                        dp[i][j] = min(dp[i][j], dp[i][1] + 1);
                        dp[i][j] = min(dp[i][j], dp[i][2] + 1);
                    }
                }
            }
        }
        // for (int j = 0; j < 3; j++) {
        // for (int i = 0; i < len; i++) {
        // cout << dp[i][j] << " ";
        // }
        // cout << endl;
        // }
        int res = len;
        for (int i = 0; i < 3; i++) {
            res = min(res, dp[len - 1][i]);
        }
        return res;
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tmp[] = { 0, 0, 2, 0 };
    // int tmp[] = { 0, 1, 2, 3, 0 };
    int len = (int)sizeof(tmp) / sizeof(int);
    vector<int> data;
    for (int i = 0; i < len; i++) {
        data.push_back(tmp[i]);
    }
    Solution s;
    cout << s.minSideJumps(data) << endl;
    return 0;
}
