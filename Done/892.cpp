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

typedef long long LL;
typedef pair<int,int> PII;

const int X[] = {1, -1, 0, 0};
const int Y[] = {0, 0, 1, -1};

class Solution {
public:
    int surfaceArea(vector<vector<int> >& grid) {
        int n = (int)grid.size();
        if (n == 0) {
            return 0;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) if (grid[i][j] > 0) {
                res += grid[i][j] * 6 - (grid[i][j] - 1) * 2;
                for (int k = 0; k < 4; k++) {
                    int x = i + X[k];
                    int y = j + Y[k];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        res -= min(grid[i][j], grid[x][y]);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int> > data;
    vector<int> row;
    row.PB(0);
    data.PB(row);
    Solution s;
    cout<<s.surfaceArea(data)<<endl;
    return 0;
}

