#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int N = 1e5 + 5;
class Solution {
public:
    int sumA[N];
    int sumB[N];
    int minimumDeletions(string s) {
        memset(sumA, 0, sizeof(sumA));
        memset(sumB, 0, sizeof(sumB));
        int len = (int)s.length();
        for (int i = 0; i < len; i++) {
            if (i > 0) sumB[i] += sumB[i - 1]; 
            if (s[i] == 'b') sumB[i]++;
        }
        for (int i = len - 1; i >= 0; i--) {
            sumA[i] += sumA[i + 1];
            if (s[i] == 'a') {
                sumA[i]++;
            }
        }
        int res = sumA[0];
        for (int i = 0; i < len; i++) {
            res = min(res, sumB[i] + sumA[i + 1]);
        }
        return res;
    }
};

int main()
{
    return 0;
}

