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
    int maxAscendingSum(vector<int>& nums)
    {
        int len = (int)nums.size();
        vector<int> res(len, 0);
        for (int i = 0; i < len; i++) {
            res[i] = nums[i];
        }
        int mx = res[0];
        for (int i = 1; i < len; i++) {
            if (nums[i] > nums[i - 1]) {
                res[i] = max(res[i], res[i - 1] + nums[i]);
            }
            mx = max(mx, res[i]);
        }
        return mx;
    }
};

int main()
{
    return 0;
}
