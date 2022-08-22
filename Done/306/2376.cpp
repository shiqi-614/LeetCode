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

class Solution {
public:
    int dp[1025][11][2][2];
    string num;
    int len;
    void getNum(int n) {
        num = "";
        while(n) {
            int tmp = n % 10;
            n /= 10;
            num += char(tmp + '0');
        }
        reverse(num.begin(), num.end());
        len = (int)num.length();
    }

    int dfs(int state, int idx, int small, int leadingZero) {
        if (idx == len) {
            return 1;
        } else {
            int &res = dp[state][idx][small][leadingZero];
            if (res != -1) return res;
            res = 0;
            int limit = num[idx] - '0';
            if (small) limit = 9;
            for (int i = 0; i <= limit; i++) if (((1<<i) & state) == 0) {
                if (i == 0) {
                    if (leadingZero) {
                        res += dfs(state, idx + 1, small == 1 ? small : i < (num[idx] - '0'), 1);
                    } else {
                        res += dfs(state | (1<<i), idx + 1, small == 1 ? small : i < (num[idx] - '0'), 0);
                    }
                } else {
                    res += dfs(state | (1<<i), idx + 1, small == 1 ? small : i < (num[idx] - '0'), 0);
                }
            }
            return res;
        }
    }

    int countSpecialNumbers(int n) {
        getNum(n); 
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, 0, 1) - 1;
    }
};

int main()
{
    Solution s;
    cout<<s.countSpecialNumbers(20)<<endl;
    cout<<s.countSpecialNumbers(5)<<endl;
    cout<<s.countSpecialNumbers(135)<<endl;
    cout<<s.countSpecialNumbers(1e9)<<endl;
    return 0;
}


