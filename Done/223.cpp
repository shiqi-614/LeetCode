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
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = getArea(A, B, C, D);
        int area2 = getArea(E, F, G, H);
        int area3 = getArea(max(A, E), max(B, F), min(C, G), min(D, H));
        return area1 + area2 - (area3 > 0? area3 : 0);
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

