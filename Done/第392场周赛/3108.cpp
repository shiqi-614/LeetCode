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

const int N = 1e5 + 5;
const int INF = ((1 << 30) - 1);
class Solution {
public:
    int fa[N];
    int fa_res[N];
    int find_fa(int idx)
    {
        if (fa[idx] != idx) {
            fa[idx] = find_fa(fa[idx]);
        }
        return fa[idx];
    }
    int unin(int u, int v, int w)
    {
        int fa_u = find_fa(u);
        int fa_v = find_fa(v);
        fa[fa_u] = fa_v;
        fa_res[fa_v] = fa_res[fa_v] & fa_res[fa_u] & w;
        return fa_v;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query)
    {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            fa_res[i] = INF;
        }

        int len = (int)edges.size();
        for (int i = 0; i < len; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            unin(u, v, w);
        }
        len = (int)query.size();
        vector<int> res;
        for (int i = 0; i < len; i++) {
            int st = query[i][0];
            int ed = query[i][1];

            if (find_fa(st) != find_fa(ed)) {
                res.push_back(-1);
            } else {
                res.push_back(fa_res[find_fa(st)]);
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
