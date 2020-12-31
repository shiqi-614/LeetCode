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

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[1][0] - points[0][0];
        int y1 = points[1][1] - points[0][1];

        int x2 = points[2][0] - points[0][0];
        int y2 = points[2][1] - points[0][1];
        if (x2 * y1 == y2 * x1) return true;
        return false;
    }
};

int main() {
    return 0;
}

