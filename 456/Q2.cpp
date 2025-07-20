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

typedef pair<int, int> PII;
typedef long long LL;

const int N = 1e5 + 5;

class Solution {
    public:
        int pre_max[N];
        int suf_max[N];
        int get_common_prefix(string s1, string s2) {
            int len = min((int)s1.length(), (int)s2.length());
            for (int i = 0; i < len; i++) {
                if (s1[i] != s2[i]) {
                    return i;
                }
            }
            return len;
        }
        vector<int> longestCommonPrefix(vector<string>& words) {
            memset(pre_max, 0, sizeof(pre_max));
            memset(suf_max, 0, sizeof(suf_max));
            int len = (int)words.size();
            for (int i = 1; i < len; i++) {
                pre_max[i] = max(pre_max[i - 1], get_common_prefix(words[i], words[i - 1]));
            }
            for (int i = len - 2; i >= 0; i--) {
                suf_max[i] = max(suf_max[i + 1], get_common_prefix(words[i], words[i + 1]));
            }

            vector<int> res;
            for (int i = 0; i < len; i++) {
                int mx = 0;
                if (i - 1 >= 0) {
                    mx = max(mx, pre_max[i - 1]);
                }
                if (i + 1 < len) {
                    mx = max(mx, suf_max[i + 1]);
                }

                if (i - 1 >= 0 && i + 1 < len) {
                    mx = max(mx, get_common_prefix(words[i - 1], words[i + 1]));
                }
                res.push_back(mx);
            }
            return res;
        }
};

int main()
{
    return 0;
}

