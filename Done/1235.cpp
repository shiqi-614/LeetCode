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
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a + ((b-a)>>1))

typedef long long LL;
typedef pair<int,int> PII;

const int N = 1e5 + 5;

struct SegTree {
    int value[N*4];
    void build(int lft, int rht, int idx) {
        if (lft == rht) {
            value[idx] = 0;
        } else {
            int mid = MID(lft, rht);
            build(lft, mid, LL(idx));
            build(mid + 1, rht, RR(idx));
        }
    }
    void update(int lft, int rht, int idx, int pos, int profit) {
        if (lft == rht) {
            value[idx] = max(value[idx], profit);
        } else {
            int mid = MID(lft, rht);
            if (pos <= mid) update(lft, mid, LL(idx), pos, profit);
            else update(mid + 1, rht, RR(idx), pos, profit);
            value[idx] = max(value[LL(idx)], value[RR(idx)]);
        }
    }
    int query(int lft, int rht, int idx, int st, int ed) {
        if (st <= lft && rht <= ed) {
            return value[idx];
        } else {
            int mid = MID(lft, rht);
            int mx1 = 0;
            int mx2 = 0;
            if (st < mid) mx1 = query(lft, mid, LL(idx), st, ed);
            if (ed > mid) mx2 = query(mid + 1, rht, RR(idx), st, ed);
            return max(mx1, mx2);
        }
    }
};

struct Node {
    int st;
    int ed;
    int profit;
    Node(){}
    Node(int st, int ed, int profit) : st(st), ed(ed), profit(profit) {}
    bool operator<(const Node &B) const {
        return st < B.st;
    }
    void print() {
        cout<<"st:"<<st<<" ed:"<<ed<<" profit:"<<profit<<endl;
    }
};
class Solution {
public:
    SegTree seg;
    vector<int> order;
    map<int, int> H;
    vector<Node> nodes;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        H.clear(); 
        nodes.clear();
        order.clear();
        int totalLen = (int)startTime.size();
        for (int i = 0; i < totalLen; i++) {
            order.push_back(startTime[i]);
            nodes.push_back(Node(startTime[i], endTime[i], profit[i]));
        }
        for (int i = 0; i < totalLen; i++) {
            order.push_back(endTime[i]);
        }

        sort(order.begin(), order.end());
        order.erase(unique(order.begin(), order.end()), order.end());
        int len = (int)order.size();

        for (int i = 0; i < len; i++) {
            H[order[i]] = i;
        }

        sort(nodes.begin(), nodes.end());
        seg.build(0, len - 1, 1);

        int res = 0;
        for (int i = 0; i < totalLen; i++) {
            int mx = seg.query(0, len - 1, 1, 0, H[nodes[i].st]) + nodes[i].profit;
//            cout<<seg.query(0, len - 1, 1, 0, H[nodes[i].st])<<" profit:"<<nodes[i].profit<<endl; 
//            cout<<"mx:"<<mx<<endl;
            res = max(res, mx);
            seg.update(0, len - 1, 1, H[nodes[i].ed], mx);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> startTime; startTime.PB(1);startTime.PB(2); startTime.PB(3);startTime.PB(3);
    vector<int> endTime; endTime.PB(3); endTime.PB(4);endTime.PB(5);endTime.PB(6);
    vector<int> profit; profit.PB(50);profit.PB(10);profit.PB(40);profit.PB(70);

    cout<<s.jobScheduling(startTime, endTime, profit)<<endl;

    return 0;
}

