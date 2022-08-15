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
    int res[N];
    int longestIdealString(string s, int k) {
        memset(res, 0, sizeof(res));
        int len = (int)s.length();
        
        for (int i = 0; i < len; i++) {
            int idx = s[i] - 'a';
            int tmp = 0;
            for (int j = max(idx - k, 0); j <= min(N - 1, idx + k); j++) {
                tmp = max(tmp, res[j]);
            }
            res[idx] = tmp + 1;
        }
        int out = 0;
        for (int i = 0; i < N; i++) {
            out = max(out, res[i]);
        }
        return out;
    }
};

int main()
{
    return 0;
}


