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
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<vector<int>> res(n - 2, vector<int>());

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                int mx = grid[i+1][j+1];
                for (int xx = 0; xx < 3; xx++) {
                    for (int yy = 0; yy < 3; yy++) {
                        mx = max(mx, grid[i+xx][j+yy]);
                    }
                }
                res[i].push_back(mx);
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}


