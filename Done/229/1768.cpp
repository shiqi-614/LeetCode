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
    string mergeAlternately(string word1, string word2)
    {
        int len1 = (int)word1.length();
        int len2 = (int)word2.length();
        int idx1 = 0;
        int idx2 = 0;
        string res = "";
        while (idx1 < len1 || idx2 < len2) {
            if (idx1 < len1) {
                res += word1[idx1++];
            }
            if (idx2 < len2) {
                res += word2[idx2++];
            }
        }
        return res;
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    return 0;
}
