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
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int len = (int)A.size();
        for (int i = len - 1; i >= 1; i--) {
            int x = A[i];
            int y = A[i - 1];
            int gap = x - y;
            auto it = upper_bound(A.begin(), A.end(), gap);
            if (it != A.end()) {
                int pos = it - A.begin();
                if (pos < i - 1) {
                    return A[pos] + A[i] + A[i - 1];
                }

            } 
        }
        return 0;
    }
};

int main() {
    return 0;
}

