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
    int countPrefixes(vector<string>& words, string s) {
        int tot = (int)words.size();
        int res = 0;
        int sLen = (int)s.length();
        for (int i = 0; i < tot ; i++) {
           int len = (int)words[i].size();
           bool flag = true;
           for (int j = 0; j < min(len, sLen); j++) {
               if (s[j] != words[i][j]) {
                   flag = false;
                   break;
               }
           }
           if (flag && len <= sLen) {
               res++;
               cout<<words[i]<<endl;
           }
        }
        return res;
    }
};

int main()
{
    return 0;
}


