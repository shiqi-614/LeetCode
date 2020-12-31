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

const int N = 505;

class Solution {
public:
    int dp[N][N];
    vector<int> nums;
    int len;
    int getLftVal(int lft) {
        int lftVal = (lft - 1 >= 0 ? nums[lft - 1] : 1);
        return lftVal;
    }
    int getRhtVal(int rht) {
        int rhtVal = (rht + 1 < len ? nums[rht + 1] : 1);
        return rhtVal;
    }
    int dfs(int lft, int rht) {
        if (lft > rht) return 0;
        if (lft == rht) {
            return nums[lft] * getLftVal(lft) * getRhtVal(rht);
        } else {
            int &res = dp[lft][rht];
            if (res != -1) return res;
            res = 0;
            for (int i = lft; i <= rht; i++) {
                res = max(res, dfs(lft, i - 1) + dfs(i + 1, rht) + nums[i] * getLftVal(lft) * getRhtVal(rht));
            } 
            return res;
        }
    }
    int maxCoins(vector<int>& nums) {
        this->nums = nums;
        this->len = (int)nums.size();
        memset(dp, -1, sizeof(dp));

        return dfs(0, len - 1);
    }
};

int main()
{

    vector<int> data;
    data.PB(3);
    data.PB(1);
    data.PB(5);
    data.PB(8);
    Solution s;
    cout<<s.maxCoins(data)<<endl;
    return 0;
}

