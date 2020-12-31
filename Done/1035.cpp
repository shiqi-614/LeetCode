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

const int N = 505;

class Solution {
public:
    int dp[N][N];
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int aLen = (int)A.size();
        int bLen = (int)B.size();
        memset(dp, 0, sizeof(dp));
        int mx = 0;
        for (int i = 0; i < aLen; i++) {
            for (int j = 0; j < bLen; j++) {
                if (i - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                if (A[i] == B[j]) {
                    if (i - 1 >= 0 && j - 1 >= 0) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                    } else {
                        dp[i][j] = 1;
                    }
                }
                mx = max(mx, dp[i][j]);
            }
        }
        return mx;
    }
};

int main() {
    vector<int> A;
    A.PB(2);
    A.PB(1);
    vector<int> B;
    B.PB(1);
    B.PB(2);
    B.PB(1);
    B.PB(3);
    B.PB(3);
    B.PB(2);
    Solution s;
    cout<<s.maxUncrossedLines(A, B)<<endl;
    return 0;
}

