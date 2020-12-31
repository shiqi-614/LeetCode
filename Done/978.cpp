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
    int maxTurbulenceSize(vector<int>& A) {
        int len = (int)A.size();
        if (len <= 1) return len;
        int state = -2;
        int mx = 0;
        int currentLen = 1;
        for (int i = 1; i < len; i++) {
            int currentState = 0;
            if (A[i] - A[i - 1] == 0) {
                currentState = 0;
            } else if (A[i] > A[i - 1]) {
                currentState = 1;
            } else {
                currentState = -1;
            }
            if (currentState != state && currentState * state != 0) {
                currentLen++;
            } else {
                if (currentState != 0) {
                    currentLen = 2;
                } else {
                    currentLen = 1;
                }
            }
            mx = max(mx, currentLen);
            state = currentState;
        }
        return mx;
    }
};

int main() {
    return 0;
}

