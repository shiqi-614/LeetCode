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
    int minElements(vector<int>& nums, int limit, int goal)
    {
        LL sum = accumulate(nums.begin(), nums.end(), 0 * 1LL);
        if (sum == goal) {
            return 0;
        } else {
            LL remain = goal - sum;
            if (remain < 0) {
                remain = remain * -1.0;
            }
            LL res = (remain / limit) + ((remain % limit) != 0);
            return res;
        }
    }
};

int main()
{
    return 0;
}
