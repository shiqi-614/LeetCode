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

const int N = 1004;

#define INF (1 << 30)
#define LL(x) (x << 1)
#define RR(x) ((x << 1) | 1)
#define MID(st, ed) (st + ((ed - st) >> 1))

struct Node {
    int x;
    int y;
    int idx;
    Node() { }
    Node(int x, int y, int idx)
        : x(x)
        , y(y)
        , idx(idx)
    {
    }
    bool operator<(const Node& B) const
    {
        if (x == B.x)
            return y < B.y;
        return x < B.x;
    }
};

struct SegTree {
    vector<PII> node;
    SegTree()
    {
        node.resize(N * 4);
    }
    void build(int lft, int rht, int idx)
    {
        if (lft == rht) {
            node[idx].first = INF;
            node[idx].second = -1;
        } else {
            int mid = MID(lft, rht);
            build(lft, mid, LL(idx));
            build(mid + 1, rht, RR(idx));
        }
    }

    void update(int lft, int rht, int idx, int pos, PII data)
    {
        if (lft == rht) {
            node[idx] = data;
        } else {
            int mid = MID(lft, rht);
            update(lft, mid, LL(idx), pos, data);
            update(mid + 1, rht, RR(idx), pos, data);
            if (node[LL(idx)].first < node[RR(idx)].first) {
                node[idx] = node[LL(idx)];
            } else {
                node[idx] = node[RR(idx)];
            }
        }
    }

    PII query(int lft, int rht, int idx, int st, int ed)
    {
        if (st <= lft && rht <= ed) {
            return node[idx];
        } else {
            int mid = MID(lft, rht);
            PII mi1 = make_pair(INF, INF);
            PII mi2 = make_pair(INF, INF);
            if (st < mid)
                mi1 = query(lft, mid, LL(idx), st, ed);
            if (ed >= mid)
                mi2 = query(mid + 1, rht, RR(idx), st, ed);
            if (mi1.first < mi2.first) {
                return mi1;
            } else {
                return mi2;
            }
        }
    }
} seg;

struct Edge {
    int x;
    int y;
    int sum;
    Edge() { }
    Edge(int x, int y, int sum)
        : x(x)
        , y(y)
        , sum(sum)
    {
    }
    bool operator<(const Edge& B) const
    {
        return sum < B.sum;
    }
};

int getDis(int x, int y, vector<vector<int>>& points)
{
    return abs(points[x][0] - points[y][0])
        + abs(points[x][1] - points[y][1]);
}

class Solution {
public:
    int len;
    int fa[N];
    vector<Edge> edges;
    int find_fa(int x)
    {
        if (fa[x] != x)
            return fa[x] = find_fa(fa[x]);
        return fa[x];
    }
    void getEdges(vector<vector<int>>& points)
    {
        vector<Node> nodes;
        vector<int> order;

        for (int i = 0; i < len; i++) {
            nodes.push_back(Node(points[i][0], points[i][1], i));
            order.push_back(points[i][1] - points[i][0]);
        }
        sort(order.begin(), order.end());
        order.erase(unique(order.begin(), order.end()), order.end());
        map<int, int> H;
        for (int i = 0; i < (int)order.size(); i++) {
            H[order[i]] = i;
        }

        seg.build(0, (int)order.size() - 1, 1);
        sort(nodes.begin(), nodes.end());
        for (int i = len - 1; i >= 0; i--) {
            Node current = nodes[i];
            int target = H[points[i][1] - points[i][0]];
            PII res = seg.query(target, (int)order.size() - 1, 1, target, (int)order.size() - 1);
            if (res.second != -1) {
                edges.push_back(Edge(current.idx, res.second, getDis(current.idx, res.second, points)));
            }
            seg.update(0, (int)order.size() - 1, 1, target, make_pair(points[i][1] + points[i][0], current.idx));
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        edges.clear();
        for (int i = 0; i < N; i++) {
            fa[i] = i;
        }

        this->len = (int)points.size();
        getEdges(points);

        for (int i = 0; i < len; i++) {
            swap(points[i][0], points[i][1]);
        }
        getEdges(points);

        for (int i = 0; i < len; i++) {
            points[i][0] = -points[i][0];
        }
        getEdges(points);

        for (int i = 0; i < len; i++) {
            swap(points[i][0], points[i][1]);
        }
        getEdges(points);
        sort(edges.begin(), edges.end());

        int res = 0;
        for (int i = 0; i < (int)edges.size(); i++) {
            int x = edges[i].x;
            int y = edges[i].y;
            if (find_fa(x) != find_fa(y)) {
                fa[find_fa(x)] = find_fa(y);
                res += edges[i].sum;
                //cout << "x:" << x << " y:" << y << " sum:" << edges[i].sum << endl;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> data;
    vector<int> tmp1;
    tmp1.push_back(0);
    tmp1.push_back(0);
    data.push_back(tmp1);
    vector<int> tmp2;
    tmp2.push_back(2);
    tmp2.push_back(2);
    data.push_back(tmp2);
    vector<int> tmp3;
    tmp3.push_back(3);
    tmp3.push_back(10);
    data.push_back(tmp3);
    vector<int> tmp4;
    tmp4.push_back(5);
    tmp4.push_back(2);
    data.push_back(tmp4);
    vector<int> tmp5;
    tmp5.push_back(7);
    tmp5.push_back(0);
    data.push_back(tmp5);
    Solution s;
    cout << s.minCostConnectPoints(data) << endl;
    return 0;
}
