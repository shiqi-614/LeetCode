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
    int longestSubarray(vector<int>& nums, int limit)
    {
        int len = (int)nums.size();
        multiset<int> order;
        int lft = 0;
        int mx = 0;
        for (int i = 0; i < len; i++) {
            order.insert(nums[i]);
            while (abs(*order.begin() - *order.rbegin()) > limit) {
                order.erase(order.find(nums[lft++]));
            }
            mx = max(mx, i - lft + 1);
        }
        return mx;
    }
};

int main()
{
    return 0;
}
