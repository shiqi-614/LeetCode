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

const long long MX = 1e10;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int len = (int)s.length();
        long long sum = 0;
        long long cur = 1;
        int res = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == '1') {
                if ((sum | cur) <= k) {
                    res++;
                    sum |= cur;
                }
            } else {
                res++;
            }
            if ((cur << 1) < MX) {
                cur = cur << 1;
            }
        }
        return res;
    }
};

int main()
{
    cout<<(2<<1)<<endl;
    return 0;
}


