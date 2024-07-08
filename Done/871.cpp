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

typedef long long LL;
typedef pair<int, int> PII;

const int N = 505;
class Solution {
public:
    LL dp[N][N];
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        memset(dp, -1, sizeof(dp));
        dp[0][0] = startFuel;
        if (target <= startFuel)
            return 0;
        vector<PII> data;
        data.push_back(MP(0, startFuel));
        for (int i = 0; i < (int)stations.size(); i++) {
            data.push_back(MP(stations[i][0], stations[i][1]));
        }
        int n = (int)data.size();
        int res = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (res != -1 && j > res)
                    continue;
                if (dp[i][j] != -1) {
                    for (int k = i + 1; k < n; k++) {
                        int tmp = data[k].first - data[i].first;
                        if (dp[i][j] >= tmp) {
                            dp[k][j + 1] = max(dp[k][j + 1], dp[i][j] + data[i].second - tmp + data[k].second);
                            if (data[k].first + dp[k][j + 1] >= target) {
                                if (res == -1) {
                                    res = j + 1;
                                } else {
                                    res = min(res, j + 1);
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
        return res;
    }
};

int main()
{
    return 0;
}
