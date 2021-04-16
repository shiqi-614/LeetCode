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

const int N = 2005;
int dp[N][N];

class Solution {
public:
    int longestPalindrome(string word1, string word2)
    {
        memset(dp, 0, sizeof(dp));
        string word = word1 + word2;
        int len = (int)word.length();
        int len1 = (int)word1.length();
        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
        }

        int mx = 0;
        for (int l = 2; l <= len; l++) {
            for (int i = 0; i < len; i++) {
                int j = i + l - 1;
                if (j < len) {
                    if (word[i] == word[j]) {
                        dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
                        if (i < len1 && j >= len1) {
                            mx = max(mx, dp[i][j]);
                        }
                    }
                    dp[i][j] = max(dp[i][j], dp[i + 1][j]);
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
            }
        }
        return mx;
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    Solution s;
    cout << s.longestPalindrome("cacb", "cbba") << endl;
    cout << s.longestPalindrome("ceebeddc", "d") << endl;
    cout << s.longestPalindrome("eeeecd", "eabfbeeb") << endl;
    cout << s.longestPalindrome("afaaadacb", "ca") << endl;
    return 0;
}
