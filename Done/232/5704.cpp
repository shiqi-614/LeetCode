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
    int maximumScore(vector<int>& nums, int k)
    {
        int lft = k;
        int rht = k;
        int len = (int)nums.size();
        int res = nums[k];
        int mi = nums[k];
        while (lft - 1 >= 0 || rht + 1 < len) {
            if (lft - 1 >= 0 && rht + 1 < len) {
                if (nums[lft - 1] > nums[rht + 1]) {
                    mi = min(mi, nums[lft - 1]);
                    lft--;
                } else {
                    mi = min(mi, nums[rht + 1]);
                    rht++;
                }
            } else if (lft - 1 >= 0) {
                mi = min(mi, nums[lft - 1]);
                lft--;
            } else {
                mi = min(mi, nums[rht + 1]);
                rht++;
            }
            cout << "mi:" << mi << " size:" << (rht - lft + 1) << " lft:" << lft << " rht:" << rht << endl;

            res = max(res, mi * (rht - lft + 1));
        }
        return res;
    }
};

int main()
{
    return 0;
}
