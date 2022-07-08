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

const int N = 1e5+5;
class Solution {
public:
    LL sum[N];
    int minimumAverageDifference(vector<int>& nums) {
        memset(sum, 0, sizeof(sum));
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            sum[i] = nums[i];
            if (i > 0) sum[i] += sum[i - 1];
            
        }
        LL res = (1<<30);
        int idx = -1;
        for (int i = 0; i < len; i++) {
            LL tmp1 = sum[i] /  (i + 1);
            LL tmp2 = 0;
            if (i != len - 1) tmp2 = (sum[len - 1] - sum[i]) / (len - i - 1);
            if (res > abs(tmp1 - tmp2)) {
                res = abs(tmp1 - tmp2);
                idx = i;
            }
        }
        return idx;
    }
};

int main()
{
    return 0;
}


