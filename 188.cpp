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

const int N = 1e3 + 5;
const int M = 105;

class Solution {
public:
    int sell[N][M];
    int buy[N][M];
    int maxProfit(int k, vector<int>& prices)
    {
        int len = (int)prices.size();
        memset(sell, -0x3f, sizeof(sell));
        memset(buy, -0x3f, sizeof(buy));
        sell[0][0] = 0;
        buy[0][0] = 0;
        buy[0][1] = -prices[0];
        for (int i = 1; i < len; i++) {
            sell[i][0] = 0;
            buy[i][0] = 0;
            for (int j = 1; j <= k; j++) {
                sell[i][j] = max(sell[i][j], buy[i - 1][j] + prices[i]);
                sell[i][j] = max(sell[i][j], sell[i - 1][j]);
                buy[i][j] = max(buy[i][j], sell[i - 1][j - 1] - prices[i]);
                buy[i][j] = max(buy[i][j], buy[i - 1][j]);
            }
        }
        int res = 0;
        for (int i = 1; i <= k; i++) {
            res = max(res, sell[len - 1][i]);
        }
        return res;
    }
};

int main()
{
    return 0;
}
