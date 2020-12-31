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

typedef long long LL;
typedef pair<int,int> PII;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = (int)nums.size();
        vector<int> dp(len, 0);
        int mx = 0;
        for (int i = 0; i < len; i++) {
            if (i >= 0 && nums[i - 1] < nums[i]) {
                dp[i] = max(dp[i], dp[i - 1] + 1);
            } else {
                dp[i] = i;
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};

int main() {
    return 0;
}

