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
const LL INF = (1LL << 60);
const LL MOD = (1e9 + 7);

class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes)
    {
        int len = (int)packages.size();
        sort(packages.begin(), packages.end());
        vector<LL> preSum(len, 0);
        for (int i = 0; i < len; i++) {
            preSum[i] += packages[i];
            if (i - 1 >= 0) {
                preSum[i] += preSum[i - 1];
            }
        }

        int n = (int)boxes.size();
        LL mi = INF;
        for (int i = 0; i < n; i++) {
            int m = (int)boxes[i].size();
            sort(boxes[i].begin(), boxes[i].end());
            if (boxes[i][m - 1] < packages[len - 1]) {
                continue;
            }

            int preIdx = -1;
            LL res = 0;
            for (int j = 0; j < m; j++) {
                int idx = -1;
                if (boxes[i][j] >= packages[len - 1]) {
                    idx = len;
                    // cout << "m" << endl;
                } else if (boxes[i][j] < packages[0]) {
                    // cout << "continue" << endl;
                    continue;
                } else {
                    // cout << "upper_bound" << endl;
                    idx = upper_bound(packages.begin(), packages.end(), boxes[i][j]) - packages.begin();
                }
                // cout << "j:" << j << " box:" << boxes[i][j] << " idx:" << idx - 1 << " package:" << packages[idx - 1] << endl;
                LL cnt = (idx - (preIdx != -1 ? preIdx + 1 : 0));
                LL sum = preSum[idx - 1] - (preIdx != -1 ? preSum[preIdx] : 0);
                // cout << "sum:" << sum << endl;
                res += (cnt * boxes[i][j] - sum);
                preIdx = idx - 1;

                if (idx == len) {
                    // cout << "break idx:" << idx << " len-1:" << len - 1 << endl;
                    break;
                }
            }
            mi = min(mi, res);
        }
        if (mi == INF)
            return -1;
        return mi % MOD;
    }
};

int main()
{
    return 0;
}
