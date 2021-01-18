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

const int N = 1005;

struct Node {
    int x;
    int y;
    int dis;
    Node()
    {
    }
    Node(int x, int y, int dis)
        : x(x)
        , y(y)
        , dis(dis)
    {
    }
    bool operator<(const Node& B) const
    {
        return dis < B.dis;
    }
};

class Solution {
public:
    int fa[N];
    int find_fa(int x)
    {
        if (fa[x] != x)
            fa[x] = find_fa(fa[x]);
        return x;
    }
    void unin(int x, int y)
    {
        int xx = find_fa(x);
        int yy = find_fa(y);
        fa[xx] = yy;
    }
    int getDis(vector<int> x, vector<int> y)
    {
        return abs(x[0] - y[0]) + abs(x[1] - y[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        for (int i = 0; i < N; i++)
            fa[i] = i;
        int len = (int)points.size();
        vector<Node> order;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                order.push_back(Node(i, j, getDis(points[i], points[j])));
            }
        }

        sort(order.begin(), order.end());

        int res = 0;
        for (int i = 0; i < (int)order.size(); i++) {
            int x = order[i].x;
            int y = order[i].y;
            if (find_fa(x) != find_fa(y)) {
                res += order[i].dis;
                unin(x, y);
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
