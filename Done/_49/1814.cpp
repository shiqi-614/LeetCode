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
const int MOD = 1e9 + 7;
class Solution {
public:
    LL getRev(int val)
    {
        LL res = 0;
        while (val) {
            int tmp = val % 10;
            res = res * 10 + tmp;
            val /= 10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums)
    {
        map<LL, LL> H;
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            LL tmp = nums[i] - getRev(nums[i]);
            H[tmp]++;
        }
        LL res = 0;
        for (auto [key, val] : H) {
            res = (res + (val * 1LL * (val - 1)) / 2) % MOD;
        }
        return res;
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    return 0;
}
