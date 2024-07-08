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

const int N = 60;

class Solution {
public:
    bool check(vector<int>& sCnt, vector<int>& tCnt)
    {
        for (int i = 0; i < N; i++) {
            if (tCnt[i] > sCnt[i]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        vector<int> tCnt(N, 0);
        for (auto& x : t) {
            tCnt[x - 'A']++;
        }

        vector<int> sCnt(N, 0);
        int len = (int)s.length();
        int lft = 0;
        int rht = -1;
        int llft = -1;
        int rrht = -1;
        int res = len + 1;
        while (1) {
            if (check(sCnt, tCnt)) {
                if (res > (rht - lft + 1)) {
                    res = rht - lft + 1;
                    llft = lft;
                    rrht = rht;
                }
                sCnt[s[lft] - 'A']--;
                lft++;
            } else {
                if (rht + 1 < len) {
                    sCnt[s[++rht] - 'A']++;
                } else {
                    if (!check(sCnt, tCnt)) {
                        break;
                    }
                }
            }
        }

        if (res == len + 1) {
            return "";
        } else {
            return s.substr(llft, rrht - llft + 1);
        }
    }
};
int main()
{
    Solution s;
    // cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    // cout << s.minWindow("a", "a") << endl;
    // cout << s.minWindow("a", "aa") << endl;
    cout << s.minWindow("abcabdebac", "cda") << endl;
    return 0;
}
