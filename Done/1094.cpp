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
    bool carPooling(vector<vector<int> >& trips, int capacity) {
        map<int, int> H;
        int len = (int)trips.size();
        for (int i = 0; i < len; i++) {
            H[trips[i][1]] += trips[i][0];
            H[trips[i][2]] -= trips[i][0];
        }
        map<int,int>::iterator it;
        int current = 0;
        for (it = H.begin(); it != H.end(); it++) {
            current += it->second;
            if (current > capacity) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}

