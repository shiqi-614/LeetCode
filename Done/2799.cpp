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

typedef long long LL;
typedef pair<int, int> PII;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums)
    {
        set<int> distict;
        map<int, int> cur;
        for (auto& x : nums) {
            distict.insert(x);
        }

        int len = (int)nums.size();
        int lft = 0;
        int rht = 0;
        int res = 0;
        int cnt = 0;
        while (lft < len) {
            cout << "lft:" << lft << " rht:" << rht << endl;
            if (cnt == (int)distict.size()) {
                res += (len - rht + 1);
                cur[nums[lft]]--;
                if (cur[nums[lft]] == 0) {
                    cnt--;
                }
                lft++;
            } else {
                if (rht < len) {
                    cur[nums[rht]]++;
                    if (cur[nums[rht]] == 1) {
                        cnt++;
                    }
                    rht++;
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
    vector<int> data({ 1, 3, 1, 2, 2 });
    Solution s;
    cout << s.countCompleteSubarrays(data) << endl;
    ;

    return 0;
}
