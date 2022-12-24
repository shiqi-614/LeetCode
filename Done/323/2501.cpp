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

const int N = 1e5+5;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int dp[N];
        map<int, int> H;
        memset(dp, 0, sizeof(dp));

        sort(nums.begin(), nums.end());
        int len = (int)nums.size();

        for (int i = 0; i < len; i++) {
            H.insert(make_pair(nums[i],i));
        }

        int res = 0;
        for (int i = 0; i < len; i++) {
            int tmp = sqrt(nums[i]);
            if (tmp * tmp == nums[i]) {
                if (H.find(tmp) == H.end()) {
                    dp[i] = 1;
                } else {
                    dp[i] = max(dp[i], dp[H[tmp]] + 1);
                }
            } else {
                dp[i] = 1;
            }
            res = max(res, dp[i]);
        }
        if (res >= 2) {
            return res;
        }
        return -1;
    }
};

int main()
{
    return 0;
}


