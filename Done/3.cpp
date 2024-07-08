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

const int N = 30;
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = (int)s.length();
        int lft = 0;
        int rht = 0;
        map<char, int> cnt;

        int mx = 0;
        for (rht = 0; rht < len; rht++) {
            char chr = s[rht];
            if (cnt.find(chr) == cnt.end() || cnt[chr] == 0) {
                cnt[chr] = 1;
                mx = max(mx, rht - lft + 1);
            } else {
                cnt[chr]++;
                while (cnt[chr] > 1) {
                    cnt[s[lft]]--;
                    lft++;
                }
            }
        }
        return mx;
    }
};

int main()
{
    return 0;
}
