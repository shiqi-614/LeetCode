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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> res;
        int len = (int)nums.size();
        vector<vector<int> > dp(3, vector<int>(len, 0));
        vector<vector<int> > pre(3, vector<int>(len, 0));

        vector<int> sum(len, 0);
        for (int i = 0; i < len; i++) {
            sum[i] = nums[i] + (i - 1 >= 0 ? sum[i - 1] : 0);
        }

        for (int i = 0; i < len; i++) {
            if (i >= k - 1) dp[0][i] = sum[i] - (i - k >= 0 ? sum[i - k] : 0);
        }

        int resMax = 0;
        int resIdx = 0;
        for (int i = 1; i <= 2; i++) {
            int preMax = -1;
            int preIdx = -1;
            for (int j = 0; j < len; j++) {
                if (j - k >= 0) {
                    if (preMax < dp[i - 1][j - k]) {
                        preMax = dp[i - 1][j - k];
                        preIdx = j - k;
                    }
                }
                int rangeSum = (sum[j] - (j - k >= 0 ? sum[j - k] : 0));
                if (dp[i][j] < preMax + rangeSum) {
                    dp[i][j] = preMax + rangeSum;
                    pre[i][j] = preIdx;
                }

                if (i == 2) {
                    if (resMax < dp[i][j]) {
                        resMax = dp[i][j];
                        resIdx = j;
                        cout<<resMax<<" "<<resIdx<<endl;
                    }
                }
            }
        }
        res.push_back(resIdx - k + 1);
        for (int i = 2; i >= 1; i--) {
            resIdx = pre[i][resIdx];
            res.push_back(resIdx - k + 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    int tmp[] = {1,2,1,2,6,7,5,1};
    vector<int> data(tmp, tmp + sizeof(tmp) / sizeof(int));
    Solution s;
    vector<int> res = s.maxSumOfThreeSubarrays(data, 2);
    for (int i = 0; i < (int)res.size(); i++) cout<<res[i]<<" "; cout<<endl;
    return 0;
}

