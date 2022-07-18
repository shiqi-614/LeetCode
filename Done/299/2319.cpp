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
    int n;
    int m;
    bool check(int x, int y) {
        if (x == y) return true;
        if (x + y == n - 1) return true;
        return false;
    }
    bool checkXMatrix(vector<vector<int>>& grid) {
        this->n =  (int)grid.size();
        this->m = (int)grid[0].size();
        for (int i = 0; i < n; i++ ) {
            for (int j = 0; j < m; j++) {
                if (check(i, j)) {
                    if (grid[i][j] == 0) {
                        return false;
                    }
                } else {
                    if (grid[i][j] != 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}


