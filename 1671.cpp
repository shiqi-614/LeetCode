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

typedef long long LL;
typedef pair<int, int> PII;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums)
    {
        int len = (int)nums.size();
        vector<int> dp1(len, 1);
        vector<int> dp2(len, 1);
        for (int i = 0; i < len; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    if (dp1[i] < dp1[j] + 1) {
                        dp1[i] = dp1[j] + 1;
                    }
                }
            }
        }

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] > nums[j]) {
                    if (dp2[i] < dp2[j] + 1) {
                        dp2[i] = dp2[j] + 1;
                    }
                }
            }
        }

        int res = len;
        for (int i = 0; i < len; i++) {
            if (dp1[i] >= 2 && dp2[i] >= 2) {
                int tmp1 = (i + 1) - (dp1[i]);
                int tmp2 = (len - i) - dp2[i];
                res = min(res, tmp1 + tmp2);
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
