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
    long long incremovableSubarrayCount(vector<int>& nums)
    {
        int len = (int)nums.size();
        int lft = 0;
        int rht = len - 2;
        LL res = 0;
        while (1) {
            if (rht >= 0 && nums[rht] < nums[rht + 1]) {
                rht--;
            } else {
                break;
            }
        }
        if (rht == -1) {
            return 1LL * (1 + len) * len / 2;
        }
        rht++;
        while (lft < len) {
            if (lft == 0) {
                res += len - rht + 1;
                // cout << "add1:" << len - rht + 1 << endl;
            } else {
                if (lft - 2 >= 0 && nums[lft - 2] >= nums[lft - 1]) {
                    break;
                }
                while (lft > rht || (rht < len && nums[lft - 1] >= nums[rht])) {
                    rht++;
                    // cout << "rht:" << rht << endl;
                }
                if (rht <= len) {
                    res += len - rht + 1;
                    // cout << "add2:" << len - rht + 1 << endl;
                }
            }
            // cout << "lft:" << lft << " rht:" << rht << " res:" << res << endl;
            lft++;
        }
        return max(res, 3LL);
    }
};

int main()
{
    Solution s;
    // vector<int> data({ 1, 2, 3, 4 });
    // vector<int> data({ 6, 5, 7, 8 });
    // vector<int> data({ 6, 5, 4, 4 });
    // vector<int> data({ 1, 2, 1, 4, 5 });
    // vector<int> data({ 9, 9 });
    // vector<int> data({ 5, 5, 6 });
    vector<int> data({ 6, 7, 5 });
    cout << s.incremovableSubarrayCount(data) << endl;
    return 0;
}
