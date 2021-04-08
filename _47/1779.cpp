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
    int nearestValidPoint(int x, int y, vector<vector<int>>& points)
    {
        int len = (int)points.size();
        int mi = (1 << 30);
        int res = -1;
        for (int i = 0; i < len; i++) {
            if (x == points[i][0] || y == points[i][1]) {
                int tmp = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (tmp < mi) {
                    mi = tmp;
                    res = i;
                }
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
