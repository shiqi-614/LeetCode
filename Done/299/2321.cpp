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

class Solution {
public:
    int getRes(vector<int>& nums1, vector<int>& nums2) {
        int len = (int)nums1.size();
        int sum = 0;
        vector<int> delta(len, 0);
        vector<int> dp(len, 0);
        for (int i = 0; i < len; i++) {
            delta[i] = nums2[i] - nums1[i];
            sum += nums1[i];
        }
        dp[0] = max(0, delta[0]);
        int mx = dp[0];
        for (int i = 1; i < len; i++) {
            dp[i] = max(dp[i-1] + delta[i], delta[i]);
            mx = max(mx, dp[i]);
        }
        return sum + mx; 
    }

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(getRes(nums1, nums2), getRes(nums2, nums1));
    }
};

int main()
{
    return 0;
}


