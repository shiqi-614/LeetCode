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

const int N = 1e3 + 5;
int dp[N][N];
bool vis[N][N];
class Solution {
public:
    int n;
    int m;
    int dfs(int idx, int st, vector<int>& nums, vector<int>& multipliers)
    {
        if (idx == m) {
            return 0;
        } else {
            int& res = dp[idx][st];
            if (vis[idx][st]) {
                return res;
            }
            vis[idx][st] = 1;
            res = INT_MIN;
            res = max(res, dfs(idx + 1, st + 1, nums, multipliers) + nums[st] * multipliers[idx]);
            res = max(res, dfs(idx + 1, st, nums, multipliers) + nums[n - 1 - (idx - st)] * multipliers[idx]);
            return res;
        }
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers)
    {
        this->n = (int)nums.size();
        this->m = (int)multipliers.size();
        memset(vis, 0, sizeof(vis));

        return dfs(0, 0, nums, multipliers);
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    return 0;
}
