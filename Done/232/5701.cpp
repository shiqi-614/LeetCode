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
    bool areAlmostEqual(string s1, string s2)
    {
        int pos1 = -1;
        int pos2 = -1;
        int cnt = 0;
        int len1 = (int)s1.length();
        int len2 = (int)s2.length();
        if (len1 != len2)
            return false;
        for (int i = 0; i < len1; i++) {
            if (s1[i] != s2[i]) {
                cnt++;
                if (pos1 == -1) {
                    pos1 = i;
                } else {
                    pos2 = i;
                }
            }
        }
        if (cnt == 0) {
            return true;
        } else if (cnt == 2) {
            swap(s1[pos1], s1[pos2]);
            return s1 == s2;
        } else {
            return false;
        }
    }
};

int main()
{
    return 0;
}
