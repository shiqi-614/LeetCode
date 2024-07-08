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
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int lft = 0;
        int rht = 0;
        int len = (int)nums.size();
        LL sum = 0;
        int res = len + 1;
        while (1) {
            if (sum < target && rht <= len) {
                sum += nums[rht++];
            } else {
                res = min(res, rht - lft);
                if (lft <= rht) {
                    sum -= nums[lft++];
                }
            }
            cout << "lft:" << lft << " rht:" << rht << " sum:" << sum << endl;
            if (rht == len && sum < target) {
                break;
            }
        }
        if (res == len + 1) {
            return 0;
        }
        return res;
    }
};

int main()
{
    return 0;
}
