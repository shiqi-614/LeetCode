#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e4 + 5;
class Solution {
public:
    bool dp[N];
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target)
    {
        int mi = N;
        int res = -1;
        int len = (int)baseCosts.size();
        for (int i = 0; i < len; i++) {
            memset(dp, 0, sizeof(dp));
            dp[baseCosts[i]] = 1;
            int len2 = (int)toppingCosts.size();
            for (int w = 0; w < len2; w++) {
                for (int k = 0; k < 2; k++) {
                    for (int j = target; j > 0; j--) {
                        if (dp[j]) {
                            if (j + toppingCosts[w] < N) {
                                dp[j + toppingCosts[w]] = 1;
                                //cout << "pre:" << j << " " << endl;
                                //cout << "next state2:" << j + toppingCosts[w] << endl;
                            }
                        }
                    }
                }
            }
            for (int j = N - 1; j > 0; j--) {
                if (dp[j]) {
                    if (abs(j - target) < mi || (abs(j - target) == mi && j < res)) {
                        mi = abs(j - target);
                        res = j;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    int tmp1[] = { 3, 10 };
    int tmp2[] = { 2, 5 };
    vector<int> data1;
    vector<int> data2;
    for (int i = 0; i < (int)sizeof(tmp1) / sizeof(int); i++) {
        data1.push_back(tmp1[i]);
    }
    for (int i = 0; i < (int)sizeof(tmp2) / sizeof(int); i++) {
        data2.push_back(tmp2[i]);
    }
    cout << s.closestCost(data1, data2, 9) << endl;
    return 0;
}
