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
class Solution {
public:
    int adj[N][N];
    int sum[N]; 
    int maximalNetworkRank(int n, vector<vector<int >>& roads) {
        memset(adj, 0, sizeof(adj));
        memset(sum, 0, sizeof(sum));

        int len = (int)roads.size();
        if (len == 0) return 0;
        for (int i = 0; i < len; i++) {
            int x = roads[i][0];
            int y = roads[i][1];
            adj[x][y] = 1;
            adj[y][x] = 1;
            sum[x]++; sum[y]++;
        }

        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mx = max(mx, sum[i] + sum[j] - adj[i][j]); 
            }
        }
        return mx;
    }
};
int main()
{
    return 0;
}

