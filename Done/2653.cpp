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

const int N = 105;
const int M = 50;

class Solution {
public:
    int cnt[N];
    int getRes(int x)
    {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (sum + cnt[i] >= x) {
                return i - M;
            }
            sum += cnt[i];
        }
        return 0;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x)
    {
        memset(cnt, 0, sizeof(cnt));
        vector<int> res;
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            cnt[nums[i] + M]++;
            if (i >= k) {
                cnt[nums[i - k] + M]--;
            }
            if (i >= k - 1) {
                int tmp = getRes(x);
                if (tmp < 0) {
                    res.push_back(tmp);
                } else {
                    res.push_back(0);
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
