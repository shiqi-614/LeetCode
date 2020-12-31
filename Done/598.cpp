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

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int len = (int)ops.size();
        if (len == 0) return n * m;
        int x = m;
        int y = n;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 2; j++) {
                x = min(x, ops[i][0]);
                y = min(y, ops[i][1]);
            }
        }
        return x * y;
    }
};
int main()
{
    return 0;
}

