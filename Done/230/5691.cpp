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
    int minOperations(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        if (sum1 < sum2) {
            swap(sum1, sum2);
            swap(nums1, nums2);
        }

        int len1 = (int)nums1.size();
        int len2 = (int)nums2.size();

        int gap = sum1 - sum2;
        int idx1 = len1 - 1;
        int idx2 = 0;
        int cnt = 0;
        while (gap) {
            int gap1 = -1;
            int gap2 = -1;
            if (idx1 >= 0) {
                gap1 = min(gap, nums1[idx1] - 1);
            }
            if (idx2 < len2) {
                gap2 = min(gap, 6 - nums2[idx2]);
            }
            if (gap1 == -1 && gap2 == -1) {
                return -1;
            }
            if (gap1 > gap2) {
                gap -= gap1;
                idx1--;
            } else {
                gap -= gap2;
                idx2++;
            }
            cnt++;
        }
        if (gap > 0) {

            return -1;
        }
        return cnt;
    }
};

int main()
{
    return 0;
}
