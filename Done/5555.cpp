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
    int dp[6][55];
    int dfs(int cur, int remain) {
        if (remain == 0) {
            return 1;
        } else {
            int &res = dp[cur][remain];
            if (res != -1) return res;
            res = 0;
            res += dfs(cur, remain - 1);
            if (cur > 0) {
                for (int i = 0; i < cur; i++) {
                    res += dfs(i, remain - 1);
                }
            }
            return res;
        }
    }
    int countVowelStrings(int n) {
        int res = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 5; i++) {
            int tmp = dfs(i, n - 1);;
            res += tmp;
            cout<<"tmp:"<<tmp<<endl;
        }
        cout<<"res:"<<res<<endl;
        return res;
    }
};

int main()
{
    return 0;
}

