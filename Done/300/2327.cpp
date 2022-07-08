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

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<vector<int>> dp(n + 1, vector<int>(forget + 1, 0));        
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = delay; j < forget; j++) {
                dp[i][1] += dp[i - 1][j];
                dp[i][1] %= MOD;
            }
            for (int j = 2; j <= forget; j++) {
                dp[i][j] = dp[i-1][j-1];
            }
        }
        // for (int i = 1; i <= n; i++) {
            // for (int j = 1; j <= forget; j++) {
                // cout<<dp[i][j]<<" ";
            // }
            // cout<<endl;
        // }
        int res = 0;
        for (int i = 1; i <= forget; i++) {
            res += dp[n][i];
            res %= MOD;
        }  
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.peopleAwareOfSecret(6, 2, 4)<<endl;
    cout<<s.peopleAwareOfSecret(4, 1, 3)<<endl;
    return 0;
}


