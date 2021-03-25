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
    int secondHighest(string s)
    {
        int len = (int)s.length();
        vector<int> data(10, 0);
        for (int i = 0; i < len; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                data[s[i] - '0'] = 1;
            }
        }
        int mx = -1;
        for (int i = 9; i >= 0; i--) {
            if (data[i]) {
                if (mx == -1) {
                    mx = i;
                } else {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}
