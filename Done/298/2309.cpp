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

const int N = 30;

class Solution {
public:
    string greatestLetter(string s) {
        bool flag1[N];
        bool flag2[N];
        memset(flag1, 0, sizeof(flag1));
        memset(flag2, 0, sizeof(flag2));

        int len = (int)s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                flag1[s[i] - 'a'] = 1;
            } else {
                flag2[s[i] - 'A'] = 1;
            }
        }

        string res = "";
        for (int i = 0; i < N; i++) {
            if (flag1[i] && flag2[i]) {
                res = char(i + 'A');
            }
        }
        return res;
    }
};
int main()
{
    return 0;
}


