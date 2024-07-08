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
    vector<LL> tot;
    int mid;
    LL calc(LL lft, LL rht, LL mmid, vector<int>& nums, LL k)
    {
        LL sum1 = (tot[rht] - tot[mmid]) - ((rht - mmid) * nums[mmid]);
        LL sum2 = 0;
        if (lft - 1 >= 0) {
            // cout << "cnt:" << (mmid - (lft) + 1) << endl;
            sum2 = (mmid - (lft) + 1) * nums[mmid] - (tot[mmid] - tot[lft - 1]);
        } else {
            sum2 = (mmid + 1) * nums[mmid] - tot[mmid];
        }
        // cout << "calc: lft" << lft << " rht:" << rht << " mid:" << mmid << " sum:" << sum1 + sum2 << endl;
        // cout << "sum1:" << sum1 << " sum2:" << sum2 << endl;
        // cout << "tot:" << tot[lft] << " " << tot[mmid] << " " << tot[rht] << endl;
        return sum1 + sum2;
    }
    bool check(LL lft, LL rht, vector<int>& nums, LL k)
    {
        LL sum = calc(lft, rht, mid, nums, k);
        if (sum <= k) {
            return true;
        } else {
            while (mid < rht) {
                LL tmpSum = calc(lft, rht, mid + 1, nums, k);
                if (tmpSum <= sum) {
                    mid++;
                    sum = tmpSum;
                } else {
                    break;
                }
            }
            if (sum <= k) {
                return true;
            }
            return false;
        }
    }
    int maxFrequencyScore(vector<int>& nums, long long k)
    {
        mid = 0;
        int len = (int)nums.size();
        tot.resize(len, 0);

        int lft = 0;
        int rht = 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            tot[i] += nums[i];
            // cout << nums[i] << " ";
            if (i - 1 >= 0) {
                tot[i] += tot[i - 1];
            }
        }
        // cout << endl;

        while (rht < len) {
            res = max(res, rht - lft + 1);
            // cout << "lft:" << lft << " rht:" << rht << " mid:" << mid << " res:" << res << endl;
            if (rht + 1 < len && check(lft, rht + 1, nums, k)) {
                rht++;
            } else {
                lft++;
                rht = max(rht, lft);
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    // data.push_back(1);
    // data.push_back(2);
    // data.push_back(6);
    // data.push_back(4);
    // cout << s.maxFrequencyScore(data, 3) << endl;
    vector<int> data({ 3, 20, 13, 2, 3, 15, 24, 19, 8, 13, 19, 20, 21 });
    cout << s.maxFrequencyScore(data, 45) << endl;
    return 0;
}
