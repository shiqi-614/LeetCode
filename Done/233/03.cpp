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
    LL idx;
    LL maxSum;
    LL n;
    LL getSum1(LL st, LL ed, LL val)
    {
        int len1 = val;
        int len2 = (ed - st + 1);
        if (len1 < len2) {
            return (1 + val) * len1 / 2 + (len2 - len1);
        } else {
            return (val + (val - len2 + 1)) * len2 / 2;
        }
    }
    LL getSum2(LL st, LL ed, LL val)
    {
        int len1 = val;
        int len2 = (ed - st + 1);
        if (len1 < len2) {
            return (1 + val) * len1 / 2 + (len2 - len1);
        } else {
            return (val + val - len2 + 1) * len2 / 2;
        }
    }
    bool check(int val)
    {
        LL sum1 = getSum1(0, idx, val);
        LL sum2 = getSum2(idx, n - 1, val);
        return sum1 + sum2 - val <= maxSum;
    }
    int maxValue(int n, int index, int maxSum)
    {
        this->n = n;
        this->maxSum = maxSum;
        this->idx = index;

        LL lft = 1;
        LL rht = maxSum;
        while (lft + 1 < rht) {
            LL mid = (lft + rht) / 2;
            if (check(mid)) {
                lft = mid;
            } else {
                rht = mid - 1;
            }
        }
        if (lft == rht) {
            return lft;
        } else {
            if (check(rht)) {
                return rht;
            } else {
                return lft;
            }
        }
    }
};

int main()
{
    Solution s;
    cout << s.maxValue(8, 2, 6) << endl;
    return 0;
}
