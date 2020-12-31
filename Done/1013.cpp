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
    bool canThreePartsEqualSum(vector<int>& A) {
        int len = (int)A.size();
        int total = accumulate(A.begin(), A.end(), 0);
        if (total % 3) {
            return false;
        }
        int cnt = 0;
        int sum = 0;
        int tmp = (total / 3);
        for (int i = 0; i < len; i++) {
            sum += A[i];
            if (sum == tmp) {
                cnt++;
                tmp += (total / 3);
            }
        }

        if (cnt == 3) {
            return true;
        }
        return false;
    }
};

int main() {
    return 0;
}

