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

#define LL(x) (x << 1)
#define RR(x) ((x << 1) | 1)
#define MID(x, y) ((x + y) >> 1)
const int N = 1e5 + 5;
struct Node {
    int val;
    int cnt;
    LL sum;
    Node() { }
};

struct SegTree {
    Node data[N * 4];
    void build(int lft, int rht, int idx)
    {
        if (lft == rht) {
            data[idx].val = lft;
            data[idx].cnt = 0;
            data[idx].sum = 0;
        } else {
            int mid = MID(lft, rht);
            build(lft, mid, LL(idx));
            build(mid + 1, rht, RR(idx));
            pushUp(idx);
        }
    }
    void pushUp(int idx)
    {
        data[idx].cnt = data[LL(idx)].cnt + data[RR(idx)].cnt;
        data[idx].sum = data[LL(idx)].sum + data[RR(idx)].sum;
    }
    void update(int lft, int rht, int idx, int pos, int val)
    {
        if (lft == rht) {
            data[idx].cnt += val;
            data[idx].sum += (data[idx].val) * val * 1LL;
        } else {
            int mid = MID(lft, rht);
            if (pos <= mid)
                update(lft, mid, LL(idx), pos, val);
            if (pos > mid)
                update(mid + 1, rht, RR(idx), pos, val);
            pushUp(idx);
        }
    }

    LL query(int lft, int rht, int idx, int tot)
    {
        if (lft == rht) {
            return 1LL * tot * data[idx].val;
        } else {
            if (data[idx].cnt <= tot) {
                return 1LL * data[idx].sum;
            } else {
                LL sum = 0;
                int mid = MID(lft, rht);
                if (tot <= data[LL(idx)].cnt) {
                    sum += query(lft, mid, LL(idx), tot);
                } else {
                    sum += query(lft, mid, LL(idx), data[LL(idx)].cnt);
                    sum += query(mid + 1, rht, RR(idx), tot - data[LL(idx)].cnt);
                }
                return sum;
            }
        }
    }
} seg;

class MKAverage {
public:
    int m;
    int k;
    queue<int> que;
    MKAverage(int m, int k)
    {
        this->m = m;
        this->k = k;
        while (!que.empty()) {
            que.pop();
        }
        seg.build(0, N - 1, 1);
    }

    void addElement(int num)
    {
        que.push(num);
        seg.update(0, N - 1, 1, num, 1);
        if ((int)que.size() > m) {
            int tmp = que.front();
            que.pop();
            seg.update(0, N - 1, 1, tmp, -1);
        }
    }

    int calculateMKAverage()
    {
        if ((int)que.size() < m) {
            return -1;
        }
        LL sum1 = seg.query(0, N - 1, 1, k);
        LL sum2 = seg.query(0, N - 1, 1, m - k);
        return (sum2 - sum1) / (m - 2 * k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    return 0;
}
