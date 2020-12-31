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

const int N = 4005;
class Solution {
public:
    int dp[N][2];
    int dfs(int pos, int flag, set<int>& forbiddenSet, int a, int b, int x) {
        if (pos == x) {
            return 0;
        } else {
            int &res = dp[pos][flag];
            if (res != -1) return res;
            res = N;
            if (pos + a < N && forbiddenSet.find(pos + 1) == forbiddenSet.end()) {
                res = min(res, dfs(pos + a, 0, forbiddenSet, a, b, x) + 1);
            }
            if (pos - b >= 0 && flag != 1 && forbiddenSet.find(pos - b) == forbiddenSet.end()) {
                res = min(res, dfs(pos - b, 1, forbiddenSet, a, b, x) + 1);
            }
            return res;
        }
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        memset(dp, -1, sizeof(dp));
        set<int> forbiddenSet;
        for (int i = 0; i < (int)forbidden.size(); i++) {
            forbiddenSet.insert(forbidden[i]);
        }

        dfs(0, 0, forbiddenSet, a, b, x);
        int res = -1;
        if (dp[x][0] == -1 && dp[x][1] == -1) res = -1; 
        else if (dp[x][0] != -1 && dp[x][1] != -1) res = min(dp[x][0], dp[x][1]);
        else {
            res = max(dp[x][0], dp[x][1]);
        }
        if (res >= N) return -1;
        else return res;
    }
};

int main()
{
    return 0;
}

