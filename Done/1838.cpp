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

typedef long long LL;
typedef pair<int, int> PII;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int len = (int)nums.size();
        LL lft = 0;
        LL rht = 0;
        LL res = 1;
        LL totalCost = 0;
        while (rht < len && lft <= rht) {

            if (rht + 1 < len) {
                LL cost = (nums[rht + 1] - nums[rht]) * (rht - lft + 1);
                // cout<<"cost:"<<cost<<" totalCost:"<<totalCost<<" lft:"<<lft<<" rht:"<<rht<<endl;
                if (totalCost + cost <= k) {
                    totalCost += cost;
                    rht++;
                    // cout<<"rht:"<<rht<<endl;
                } else {
                    totalCost -= nums[rht] - nums[lft];
                    lft++;
                    if (rht < lft)
                        rht++;
                    // cout<<"lft:"<<lft<<endl;
                }
            } else {
                break;
            }
            res = max(res, rht - lft + 1);
        }

        return res;
    }
};

int main()
{
    return 0;
}
