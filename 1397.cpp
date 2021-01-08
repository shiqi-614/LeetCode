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

const int N = 505;
const int M = 55;
const LL MOD = 1e9 + 7;
class Solution {
public:
    LL dp[N][M][2][2];
    string s1;
    string s2;
    string evil;
    int len;
    int evilIndex[M][30];
    LL dfs(int idx, int evilLen, int bigger, int smaller)
    {
        if (evilLen >= (int)evil.length())
            return 0;
        if (idx == len)
            return 1;

        LL& res = dp[idx][evilLen][bigger][smaller];
        if (res != -1)
            return res;

        res = 0;
        char st = 'a';
        char ed = 'z';
        if (!bigger)
            st = s1[idx];
        if (!smaller)
            ed = s2[idx];
        for (char i = st; i <= ed; i++) {
            if (evil[evilLen] == i) {
                res = (res + dfs(idx + 1, evilLen + 1, bigger ? bigger : i > s1[idx], smaller ? smaller : i < s2[idx])) % MOD;
            } else {
                //res = (res + dfs(idx + 1, 0, bigger ? bigger : i > st, smaller ? smaller : i < ed)) % MOD;
                res = (res + dfs(idx + 1, evilIndex[evilLen][i - 'a'], bigger ? bigger : i > s1[idx], smaller ? smaller : i < s2[idx])) % MOD;
            }
        }
        return res % MOD;
    }
    int getSingleEvilIndex(string evil, string current)
    {
        int len = (int)current.length();
        int res = 0;
        for (int i = 0; i < len; i++) {
            bool flag = true;
            for (int j = 0; i + j < len; j++) {
                if (evil[j] == current[i + j]) {
                    continue;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                //cout << "evil:" << evil << " current:" << current << " res:" << len - i << endl;
                return len - i;
            }
        }
        return 0;
    }
    void getEvilIndex(string evil)
    {
        for (int i = 0; i < (int)evil.length(); i++) {
            for (char j = 'a'; j <= 'z'; j++) {
                evilIndex[i][j - 'a'] = getSingleEvilIndex(evil, evil.substr(0, i) + j);
                //cout << evilIndex[i][j - 'a'] << " ";
            }
            //cout << endl;
        }
        //cout << "end" << endl;
    }
    int findGoodStrings(int n, string s1, string s2, string evil)
    {
        this->s1 = s1;
        this->s2 = s2;
        this->evil = evil;
        this->len = n;
        memset(dp, -1, sizeof(dp));
        memset(evilIndex, 0, sizeof(evilIndex));
        getEvilIndex(evil);
        return dfs(0, 0, 0, 0);
    }
};

int main()
{
    Solution s;
    cout << s.findGoodStrings(2, "aa", "da", "b") << endl;
    cout << s.findGoodStrings(8, "leetcode", "leetgoes", "leet") << endl;
    cout << s.findGoodStrings(2, "gx", "gz", "x") << endl;
    cout << s.findGoodStrings(2, "gx", "gz", "x") << endl;
    cout << s.findGoodStrings(8, "pzdanyao", "wgpmtywi", "sdka") << endl;
    return 0;
}
