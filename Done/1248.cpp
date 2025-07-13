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

typedef pair<int, int> PII;
typedef long long LL;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int> H;
        int sum = 0;
        int res = 0;
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            sum += nums[i]%2;
            H[sum]++;
            if (sum - k >= 0) {
                res += H[sum - k];
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}


