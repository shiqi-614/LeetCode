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

class Solution {
public:
    int getIdx(char chr)
    {
        return chr - 'a' + 1;
    }
    string subStrHash(string s, int power, int modulo, int k, int hashValue)
    {
        int len = (int)s.length();
        LL res = 0;
        LL pow = 1;
        for (int i = 0; i < k; i++) {
            res = (res + getIdx(s[len - k + i]) * pow) % modulo;
            if (i != k - 1) {
                pow = (pow * power) % modulo;
            }
        }
        int idx = -1;
        if (res == hashValue) {
            idx = len - k;
        }
        for (int i = len - 1; i >= k; i--) {
            res = (res - (getIdx(s[i]) * pow) % modulo);
            res = (res + modulo) % modulo;
            res = (res * power + getIdx(s[i - k])) % modulo;
            if (res == hashValue) {
                idx = i - k;
            }
        }
        // cout << "idx:" << idx << endl;
        return s.substr(idx, k);
    }
};

int main()
{
    // cout << 'o' - 'a' + 1 << endl;
    Solution s;
    // cout << s.subStrHash("leetcode", 7, 20, 2, 0) << endl;
    cout << s.subStrHash("fbxz", 31, 100, 3, 32) << endl;
    return 0;
}
