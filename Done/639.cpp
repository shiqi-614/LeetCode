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

const LL MOD = 1e9 + 7;
class Solution {
public:
    int calc(char c1, char c2) {
        if (c1 == '*' && c2 == '*') {
            return 15;
        } else if (c1 == '*') {
            if (c2 <= '6') return 2;
            else return 1;
        } else if (c2 == '*') {
            if (c1 == '1') return 9;
            else if (c1 == '2') return 6;
            else return 0;
        } else {
            int tmp = (c1 - '0') * 10 + (c2 - '0');
            if (tmp >= 10 && tmp <= 26) return 1;
            else return 0;
        }
    }
    int numDecodings(string s) {
        int len = (int)s.length();
        if (len == 0) return 0;
        vector<LL> dp(len + 1, 0);;

        dp[0] = 1;
        for (int i = 0; i < len; i++) {
            if (s[i] == '*') {
                dp[i + 1] = (dp[i + 1] + dp[i] * 9) % MOD;
            } else {
                if (s[i] != '0') {
                    dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
                }
            }
            if (i - 1 >= 0) {
                dp[i + 1] = (dp[i + 1] + dp[i - 1] * calc(s[i - 1], s[i])) % MOD;
            }
        }

        return (int)dp[len];
    }
};

int main()
{
    Solution s;
    cout<<s.numDecodings("*")<<endl;
    cout<<s.numDecodings("1*")<<endl;
    
    return 0;
}

