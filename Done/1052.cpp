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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int len = (int)customers.size();
        int sum = 0;
        int total = 0;
        for (int i = 0; i < len; i++) {
            if (grumpy[i] == 1) {
                sum += customers[i];
            }
            total += customers[i];
        }
        int mx = 0;
        int tmp = 0;
        for (int i = 0; i < len; i++) {
            if (grumpy[i] == 1) {
                tmp += customers[i];
            }
            if (i > X) {
                if (grumpy[i - X] == 1) {
                    tmp -= customers[i - X];
                }
            }
            mx = max(mx, tmp);

        }
        return total - (sum - mx);

    }
};

int main() {
    return 0;
}

