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
    string removeStars(string s)
    {
        int len = (int)s.length();
        string res = "";
        int cnt = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == '*') {
                cnt++;
            } else {
                if (cnt > 0) {
                    cnt--;
                } else {
                    res += s[i];
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    return 0;
}
