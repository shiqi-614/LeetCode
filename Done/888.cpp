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
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int tmp = (sumB - sumA) / 2;
        vector<int> res;
        for (int i = 0; i < (int)A.size(); i++) {
            int value = tmp + A[i];
            auto pos = lower_bound(B.begin(), B.end(), value);
            if (pos != B.end()) {
                res.push_back(A[i]);
                res.push_back(*pos);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

