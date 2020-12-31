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

const int N = 30;
class Solution {
public:
    bool isExist(vector<int>& cnts, int idx) {
        int cnt = cnts[idx];
        for (int i = 0; i < N; i++) if (i != idx) {
            if (cnts[i] == cnts[idx] ) return true;
        }
        return false;
    }
    int minDeletions(string s) {
        vector<int> cnts(N, 0);
        int len = (int)s.length();
        int res = 0;
        for (int i = 0; i < len; i++) {
            cnts[s[i] - 'a']++;
        }
        for (int i = 0; i < N; i++) if (cnts[i] > 0) {
            while (isExist(cnts, i) && cnts[i] > 0) {
                cnts[i]--;
                res++;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}

