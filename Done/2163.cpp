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
    long long minimumDifference(vector<int>& nums)
    {
        int len = (int)nums.size();
        int n = len / 3;
        vector<LL> lft(len, 0);
        vector<LL> rht(len, 0);

        priority_queue<int> que;
        for (int i = 0; i < len; i++) {
            if (i != 0) {
                lft[i] += lft[i - 1];
            }
            if (que.size() < n) {
                que.push(nums[i]);
                lft[i] += nums[i];
            } else {
                if (que.top() > nums[i]) {
                    int tmp = que.top();
                    // cout << "i:" << i << " top:" << tmp << endl;
                    que.pop();
                    que.push(nums[i]);
                    lft[i] -= tmp;
                    lft[i] += nums[i];
                }
            }
            // cout << lft[i] << " ";
        }
        // cout << endl;
        priority_queue<int, vector<int>, greater<int>> que2;
        for (int i = len - 1; i >= 0; i--) {
            if (i != len - 1) {
                rht[i] += rht[i + 1];
            }
            if (que2.size() < n) {
                que2.push(nums[i]);
                rht[i] += nums[i];
            } else {
                if (que2.top() < nums[i]) {
                    int tmp = que2.top();
                    // cout << "i:" << i << " top:" << tmp << endl;
                    que2.pop();
                    que2.push(nums[i]);
                    rht[i] -= tmp;
                    rht[i] += nums[i];
                }
            }
        }
        // for (int i = 0; i < len; i++) {
        // cout << rht[i] << " ";
        // }
        // cout << endl;
        LL mi = 1LL << 60;
        for (int i = n - 1; i < 2 * n; i++) {
            mi = min(mi, lft[i] - rht[i + 1]);
        }
        return mi;
    }
};

int main()
{

    vector<int> data;
    data.push_back(3);
    data.push_back(1);
    data.push_back(2);
    Solution s;
    cout << s.minimumDifference(data) << endl;
    return 0;
}
