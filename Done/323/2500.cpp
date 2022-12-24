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
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int len = (int)grid.size();
        for (int i = 0; i < len; i++) {
            sort(grid[i].begin(), grid[i].end());
        }        
        int res = 0;
        int m = (int)grid[0].size();
        for (int j = m - 1; j >= 0; j--) {
            int mx = 0;
            for (int k = 0; k < len; k++) {
                mx = max(mx, grid[k][j]);
            }
            res += mx;
        }
        return res;

    }
};

int main()
{
    return 0;
}


