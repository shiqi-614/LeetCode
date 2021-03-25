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
    int getMaximumConsecutive(vector<int>& coins)
    {
        int len = (int)coins.size();
        sort(coins.begin(), coins.end());
        int st = 0;
        int ed = 0;
        for (int i = 0; i < len; i++) {
            int nxtSt = st + coins[i];
            int nxtEd = ed + coins[i];
            if (nxtSt <= ed + 1) {
                ed = nxtEd;
            } else {
                break;
            }
        }
        return ed + 1;
    }
};

int main()
{
    return 0;
}
