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
    int getSum(int num) {
        int sum = 0;
        while(num > 0) {
            sum += (num%10);
            num/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        map<int, int> H;
        int res = -1;
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            int sum = getSum(nums[i]);
            if (H.find(sum) == H.end()) {
                H.insert(make_pair(sum, nums[i]));
            } else {
                res = max(res, H[sum] + nums[i]);
                if (H[sum] < nums[i])  {
                    H[sum] = nums[i];
                }
            }
        }
        return res;

    }
};
int main()
{
    return 0;
}


