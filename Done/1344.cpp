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
    double angleClock(int hour, int minutes) {
        double angleOfMinute = minutes * 6;
        double angleOfHour = (hour * 30) % 360 + (( 1.0 / 2.0) * minutes);

        double res = abs(angleOfHour - angleOfMinute);

        res = min(res, abs(360 - angleOfMinute + angleOfHour));
        res = min(res, abs(360 - angleOfHour + angleOfMinute));
        return res;
    }
};


int main() {
    Solution s;
    cout<<s.angleClock(12, 30)<<endl;
    return 0;
}

