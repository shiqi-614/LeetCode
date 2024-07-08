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

const int N = 1e5 + 5;

#define LL(idx) (idx << 1)
#define RR(idx) ((idx << 1) | 1)
#define MID(lft, rht) ((lft + rht) / 2)

struct Segtree {
    int mx[N * 4];
    void build(int lft, int rht, int idx)
    {
        mx[idx] = 0;
        if (lft == rht)
            return;
        int mid = MID(lft, rht);
        build(lft, mid, LL(idx));
        build(mid + 1, rht, RR(idx));
    }
    void update(int lft, int rht, int idx, int pos, int val)
    {
        if (lft == rht) {
            mx[idx] = val;
        } else {
            int mid = MID(lft, rht);
            if (pos <= mid) {
                update(lft, mid, LL(idx), pos, val);
            } else {
                update(mid + 1, rht, RR(idx), pos, val);
            }
            mx[idx] = max(mx[LL(idx)], mx[RR(idx)]);
        }
    }
    int query(int lft, int rht, int idx, int st, int ed)
    {
        if (st <= lft && rht <= ed) {
            return mx[idx];
        } else {
            int mid = MID(lft, rht);
            int mx1 = 0;
            int mx2 = 0;
            if (st <= mid) {
                mx1 = query(lft, mid, LL(idx), st, ed);
            }

            if (ed >= mid + 1) {
                mx2 = query(mid + 1, rht, RR(idx), st, ed);
            }
            return max(mx1, mx2);
        }
    }
} seg;

struct Node {
    int val;
    int pos;
    Node() { }
    Node(int val, int pos)
        : val(val)
        , pos(pos)
    {
    }
    bool operator<(const Node& node) const
    {
        if (val != node.val) {
            return val < node.val;
        }
        return pos < node.pos;
    }
    void print()
    {
        cout << val << " " << pos << endl;
    }
};
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles)
    {
        int len = (int)obstacles.size();
        vector<Node> order;
        for (int i = 0; i < len; i++) {
            order.push_back(Node(obstacles[i], i));
        }
        sort(order.begin(), order.end());
        // for (int i = 0; i < len; i++) {
        // order[i].print();
        // }
        seg.build(0, len - 1, 1);

        vector<int> res(len, 1);
        for (int i = 0; i < len; i++) {
            int val = order[i].val;
            int pos = order[i].pos;
            if (pos - 1 >= 0) {
                int mx = seg.query(0, len - 1, 1, 0, pos - 1);
                res[pos] = mx + 1;
            }
            seg.update(0, len - 1, 1, pos, res[pos]);
        }
        // for (int i = 0; i < len; i++) {
        // cout << res[i] << " ";
        // }
        // cout << endl;
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    data.push_back(2);
    s.longestObstacleCourseAtEachPosition(data);
    return 0;
}
