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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int N = 105;
#define INF 1<< 30

class Solution {
public:
    int dp[N][N][N];
    int dis[N][N];
    void getDis(vector<int>& houses) {
        int len = (int)houses.size();
        memset(dis, 0, sizeof(dis));
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int lft = i;
                int rht = j;
                while(lft < rht) {
                    dis[i][j] += houses[rht] - houses[lft];
                    lft++;
                    rht--;
                }
            }
        }
    }
    int dfs(int lft, int rht, int k, vector<int>& houses) {
        if (k == 1) {
            return dis[lft][rht];
        } else {
            int& res = dp[lft][rht][k];
            if (res != -1) return res;
            res = INF;
            for (int i = rht; i > lft; i--) {
                res = min(res, dfs(lft, i - 1, k - 1, houses) + dis[i][rht]);
            }
            return res;
        }
    }
    int minDistance(vector<int>& houses, int k) {
        memset(dp, -1, sizeof(dp));
        sort(houses.begin(), houses.end());
        int len = (int)houses.size();
        getDis(houses);
        return dfs(0, len - 1, k, houses);
    }
};

int main()
{
    return 0;
}

