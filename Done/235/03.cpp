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
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2)
    {
        int len = (int)nums1.size();
        int mx = 0;
        int idx = -1;
        for (int i = 0; i < len; i++) {
            int tmp = abs(nums1[i] - nums2[i]);
            if (tmp > mx) {
                mx = tmp;
                idx = i;
            }
        }

        if (idx != -1) {
            int resIdx = -1;
            for (int i = 0; i < len; i++) {
                int tmp = abs(nums1[i] - nums2[idx]);
                if (tmp <= mx) {
                    mx = tmp;
                    resIdx = i;
                }
            }
            nums1[idx] = nums1[resIdx];
        }

        LL res = 0;
        for (int i = 0; i < len; i++) {
            res = (res + abs(nums1[i] - nums2[i])) % MOD;
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
