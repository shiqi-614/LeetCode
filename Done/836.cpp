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
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        LL area3 = getArea(max(rec1[0], rec2[0]), max(rec1[1], rec2[1]), min(rec1[2], rec2[2]), min(rec1[3], rec2[3]));
        
        if (area3 > 0) {
            return true;
        }
        return false;
    }

    LL getArea(LL x1, LL y1, LL x2, LL y2) {
        if (x1 < x2 && y1 < y2) {
            return (x2 - x1) * (y2 - y1);
        }
        return -1;
    }

};

int main() {
    return 0;
}

