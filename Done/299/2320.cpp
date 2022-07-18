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

const int N = 1e4 + 5;
const LL MOD = 1e9 + 7;
class Solution {
public:
    int countHousePlacements(int n) {
        LL dp[N][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            dp[i][1] = dp[i-1][0];
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        }
        LL tmp = (dp[n-1][0] + dp[n-1][1]) % MOD;
        return (tmp * tmp) % MOD;
    }
};

int main()
{
    Solution s;
    cout<<s.countHousePlacements(1)<<endl;
    cout<<s.countHousePlacements(2)<<endl;
    return 0;
}


