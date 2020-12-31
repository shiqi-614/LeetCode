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
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int len = (int)A.size();
        if (len <= 0) return 0;
        int current = A[0];
        int res = 0;
        for (int i = 1; i < len; i++) {
            if (A[i] < current + 1) {
                res += current + 1 - A[i];
                current += 1;
            } else {
                current = A[i];
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

