#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len = (int)nums.size();
        int lft = 0;
        int rht = 0;
        int sum = 0;
        int cnt = 0;
        int res = len;
        while(1) {
            if (sum > x) break;
            if (lft < len) {
                sum += nums[lft];
                lft++;
                cnt++;
            } else {
                break;
            }
        }

        if (lft >= len) return -1;
        lft--;

        if (sum == x) res = min(res, cnt);
        while (1) {
            if (sum == x) res = min(res, cnt);

            if (sum < x) {
                if (rht > lft) {
                    sum += nums[rht--];
                    cnt++;
                } else {
                    break;
                }
            } else if (sum >= x) {
                if (lft >= 0) {
                    sum -= nums[lft];
                    lft--;
                    cnt--;
                } else {
                    break;
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

