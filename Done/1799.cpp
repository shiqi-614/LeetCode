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

int dp[17384][7];
class Solution {
public:
    int len;
    int gcd(int val1, int val2)
    {
        if (val1 % val2 == 0) {
            return val2;
        } else {
            return gcd(val2, val1 % val2);
        }
    }
    int dfs(int state, int idx, vector<int>& nums)
    {
        if (state == ((1 << len) - 1)) {
            return 0;
        } else {
            int& res = dp[state][idx];
            if (res != -1) {
                return res;
            }
            res = 0;
            for (int i = 0; i < len; i++) {
                if ((state & (1 << i)) == 0) {
                    for (int j = i + 1; j < len; j++) {
                        if ((state & (1 << j)) == 0) {
                            res = max(res, gcd(nums[i], nums[j]) * (idx + 1) + dfs(state | (1 << i) | (1 << j), idx + 1, nums));
                        }
                    }
                }
            }
            return res;
        }
    }
    int maxScore(vector<int>& nums)
    {
        len = (int)nums.size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, nums);
    }
};

int main()
{
    int tmp[] = { 1, 2 };
    int tmp[] = { 3, 4, 6, 8 };
    // int tmp[] = { 3, 4, 5, 2, 1, 7, 3, 4, 7 };
    // int tmp[] = { 1, 2, 4, 1, 2, 5, 1, 2, 6 };
    // int tmp[] = { 1, 2, 0, 3, 0 };
    int len = sizeof(tmp) / sizeof(int);
    vector<int> data;
    for (int i = 0; i < len; i++) {
        data.push_back(tmp[i]);
    }
    Solution s;
    cout << s.maxScore(data) << endl;
    return 0;
}
