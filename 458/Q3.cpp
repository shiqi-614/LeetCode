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

class Solution {
    public:
        string ss;
        LL get_total_length(string s) {
            LL tot = 0;
            int len = (int)s.length();
            for (int i = 0; i < len; i++) {
                if (s[i] >='a' && s[i] <= 'z') {
                    tot += 1;
                } else if (s[i] == '#') {
                    tot *= 2;
                } else if (s[i] == '%') {
                    continue;
                } else if (s[i] == '*') {
                    tot = max(0LL, tot - 1);
                }
            }
            return tot;
        }

        char dfs(LL tot, int len,  LL k) {
            //cout<<"tot:"<<tot<<" len:"<<len<<" k:"<<k<<endl;
            if (len < 0) {
                return '.';
            }

            if (ss[len] == '#') {
                tot /= 2;
                k %= tot;
                return dfs(tot, len - 1, k);
            } else if (ss[len] == '%') {
                k = tot - k - 1;
                return dfs(tot, len - 1, k);
            } else if (ss[len] == '*') {
                return dfs(tot + 1, len - 1, k);
            } else {
                if (k + 1 == tot) {
                    return ss[len];
                } else {
                    return dfs(tot - 1, len - 1, k);
                }
            }
        }
        char processStr(string s, long long k) {
            ss = "";
            bool find = 0;

            for (int i = 0; i < (int)s.length(); i++) {
                if (find) {
                    ss += s[i];
                } else if (s[i] >= 'a' && s[i] <= 'z') {
                    find = 1;
                    ss += s[i];
                }

            }
            LL tot = get_total_length(ss);
            if (tot == 0 || tot <= k) {
                return '.';
            }

            return dfs(tot, (int)ss.length() - 1, k);
        }
};

int main()
{
    return 0;
}

