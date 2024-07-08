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
    long long countSubarrays(vector<int>& nums, long long k)
    {
        int len = (int)nums.size();
        int lft = 0;
        int rht = 0;
        LL sum = 0;
        LL res = 0;
        while (lft < len) {
            // cout << "lft:" << lft << " rht:" << rht << endl;
            if (rht < len && (sum + nums[rht]) * (rht - lft + 1) < k) {
                sum = sum + nums[rht];
                rht++;
            } else {
                // cout << "res is:" << lft << " rht:" << rht << endl;
                res += (rht - lft);
                sum = sum - nums[lft];
                lft++;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> data({ 2, 1, 4, 3, 5 });
    cout << s.countSubarrays(data, 10) << endl;

    // vector<int> data({ 1, 1, 1 });
    // cout << s.countSubarrays(data, 5) << endl;
    return 0;
}
