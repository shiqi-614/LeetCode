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
    void update(string& s, int idx, int& k)
    {
        int now = s[idx] - 'a';
        int tmp1 = now;
        int tmp2 = now;
        if (now == 0)
            return;
        while (k > 0) {
            tmp1 = (tmp1 + 1) % 26;
            tmp2 = tmp2 - 1;
            now = min(tmp1, tmp2);
            k--;
            s[idx] = now + 'a';
            if (now == 0)
                return;
        }
    }
    string getSmallestString(string s, int k)
    {
        int len = (int)s.length();
        for (int i = 0; i < len; i++) {
            update(s, i, k);
        }
        return s;
    }
};

int main()
{
}
