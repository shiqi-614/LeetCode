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

const int N = 1e4 + 5;
#define LL(x) (x << 1)
#define INF (1 << 30)
#define RR(x) ((x << 1) | 1)
#define MID(a, b) (a + ((b - a) >> 1))

struct SegTree {
    int miPos[N * 4];
    void build(int lft, int rht, int idx)
    {
        miPos[idx] = INF;
        if (lft == rht)
            return;
        int mid = MID(lft, rht);
        build(lft, mid, LL(idx));
        build(mid + 1, rht, RR(idx));
    }
    void update(int lft, int rht, int idx, int pos, int val)
    {
        if (lft == rht) {
            miPos[idx] = min(val, miPos[idx]);
        } else {
            int mid = MID(lft, rht);
            if (pos <= mid)
                update(lft, mid, LL(idx), pos, val);
            if (pos > mid)
                update(mid + 1, rht, RR(idx), pos, val);
            miPos[idx] = min(miPos[LL(idx)], miPos[RR(idx)]);
        }
    }
    int query(int lft, int rht, int idx, int st, int ed)
    {
        if (st > ed) {
            return INF;
        }
        if (st <= lft && rht <= ed) {
            return miPos[idx];
        } else {
            int mid = MID(lft, rht);
            int mi1 = INF;
            int mi2 = INF;
            if (st <= mid)
                mi1 = query(lft, mid, LL(idx), st, ed);
            if (ed > mid)
                mi2 = query(mid + 1, rht, RR(idx), st, ed);
            return min(mi1, mi2);
        }
    }
} seg;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int len = (int)nums.size();
        vector<int> order = nums;
        map<int, int> H;
        vector<int> res(len, INF);

        if (len == 0) {
            return res;
        }

        sort(order.begin(), order.end());
        order.erase(unique(order.begin(), order.end()), order.end());
        for (int i = 0; i < (int)order.size(); i++) {
            H[order[i]] = i;
        }

        int ed = (int)order.size() - 1;
        seg.build(0, ed, 1);
        //cout << "build" << endl;
        for (int i = len - 1; i >= 0; i--) {
            int pos = seg.query(0, ed, 1, H[nums[i]] + 1, ed);
            if (pos != INF) {
                //cout << "loop1" << endl;
                //cout << "i:" << i << " nums:" << nums[i] << " st:" << H[nums[i]] + 1 << " ed:" << ed << endl;
                //cout << "res i:" << i << " pos:" << pos << "valu:" << nums[pos] << endl;
                res[i] = nums[pos];
            }
            seg.update(0, ed, 1, H[nums[i]], i);
        }
        seg.build(0, ed, 1);
        for (int i = 0; i < len; i++) {
            if (res[i] == INF) {
                int pos = seg.query(0, ed, 1, H[nums[i]] + 1, ed);
                if (pos != INF) {
                    res[i] = nums[pos];
                    //cout << "loop2" << endl;
                    //cout << "i:" << i << " nums:" << nums[i] << " st:" << H[nums[i]] + 1 << " ed:" << ed << endl;
                    //cout << "res i:" << i << " pos:" << pos << endl;
                }
            }
            seg.update(0, ed, 1, H[nums[i]], i);
        }
        for (int i = 0; i < len; i++) {
            if (res[i] == INF) {
                res[i] = -1;
            }
        }

        return res;
    }
};

int main()
{
    //int tmp[] = { 1, 2, 1 };
    //int tmp[] = { 5, 4, 3, 2, 1 };
    //int tmp[] = { 1, 2, 3, 2, 1 };
    int tmp[] = { 1, 8, -1, -100, -1, 222, 1111111, -111111 };
    vector<int> data;
    for (int i = 0; i < (int)sizeof(tmp) / sizeof(int); i++) {
        data.push_back(tmp[i]);
    }
    Solution s;
    vector<int> res = s.nextGreaterElements(data);
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
