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



const int N = 205;

class Solution {
public:
    map<pair<int, int>, int> price;
    long long dp[N][N];
    long long dfs(int m, int n) {
        if (m == 0 || n == 0) {
            return 0;
        }
        long long &res = dp[m][n];
        if (res != -1) {
            return res;
        }
        if (price.find(make_pair(m, n)) != price.end()) {
            res = price[make_pair(m, n)];
        } else {
            res = 0;
        }
        if (m > 1) {
            for (int i = 1; i < m; i++) {
                res = max(res, dfs(i, n) + dfs(m - i, n));
            }
        }
        if (n > 1) {
            for (int i = 1; i < n; i++) {
                res = max(res, dfs(m, i) + dfs(m, n - i));
            }
        }
        return res;
    }

    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        memset(dp, -1, sizeof(dp));
        this->price.clear();
        int len = (int)prices.size();
        for (int i = 0; i < len; i++) {
            price.insert(make_pair(make_pair(prices[i][0], prices[i][1]), prices[i][2]));
        }

        return dfs(m, n);
    }
};



int main()
{
    return 0;
}


