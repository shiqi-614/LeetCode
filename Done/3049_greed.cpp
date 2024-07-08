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
    bool check(int pos, vector<int>& nums, vector<int>& changeIndices, vector<int>& firstPos)
    {
        // cout << "check:" << pos << endl;
        LL cnt = 0;
        LL slow = accumulate(nums.begin(), nums.end(), (LL)nums.size());
        priority_queue<int, vector<int>, greater<>> que;
        for (int i = pos; i >= 0; i--) {
            if (firstPos[changeIndices[i] - 1] != i) {
                cnt++;
            } else {
                int num = nums[changeIndices[i] - 1];
                if (num == 0) {
                    cnt++;
                    continue;
                }

                if (cnt > 0) {
                    // cout << "push:" << num << endl;
                    que.push(num);
                    slow -= num + 1;
                    cnt--;
                } else {
                    if (!que.empty() && que.top() < num) {
                        cout << "pop:" << que.top() << endl;
                        slow += que.top() + 1;
                        que.pop();
                        // cout << "swap:" << num << endl;
                        que.push(num);
                        slow -= num + 1;
                    } else {
                    }
                    cnt++;
                }
            }
        }
        // cout << "pos:" << pos << " cnt:" << cnt << " slow:" << slow << endl;
        return cnt >= slow;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices)
    {
        int n = (int)nums.size();
        int m = (int)changeIndices.size();
        vector<int> firstPos(n, 0);
        for (int i = m - 1; i >= 0; i--) {
            firstPos[changeIndices[i] - 1] = i;
        }

        int lft = 0;
        int rht = m - 1;
        while (lft < rht) {
            int mid = (lft + rht) / 2;
            if (check(mid, nums, changeIndices, firstPos)) {
                rht = mid;
            } else {
                lft = mid + 1;
            }
        }
        if (lft == rht && check(lft, nums, changeIndices, firstPos)) {
            return lft + 1;
        }
        return -1;
    }
};

int main()
{
    return 0;
}
