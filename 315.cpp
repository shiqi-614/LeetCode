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

#define LL(x) (x << 1)
#define RR(x) ((x << 1) | 1)
#define MID(lft, rht) ((lft + rht) / 2)

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5;
struct SegTree {
    int sum[N * 4];
    void build(int lft, int rht, int idx)
    {
        sum[idx] = 0;
        if (lft == rht)
            return;
        int mid = MID(lft, rht);
        build(lft, mid, LL(idx));
        build(mid + 1, rht, RR(idx));
    }
    void update(int lft, int rht, int idx, int pos)
    {
        if (lft == rht) {
            sum[idx]++;
        } else {
            int mid = MID(lft, rht);
            if (pos <= mid) {
                update(lft, mid, LL(idx), pos);
            } else {
                update(mid + 1, rht, RR(idx), pos);
            }
            sum[idx] = sum[LL(idx)] + sum[RR(idx)];
        }
    }
    int query(int lft, int rht, int idx, int st, int ed)
    {
        if (st <= lft && rht <= ed) {
            return sum[idx];
        } else {
            int mid = MID(lft, rht);
            int sum1 = 0;
            int sum2 = 0;
            if (st <= mid)
                sum1 = query(lft, mid, LL(idx), st, ed);
            if (ed > mid)
                sum2 = query(mid + 1, rht, RR(idx), st, ed);
            return sum1 + sum2;
        }
    }
} seg;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        int len = (int)nums.size();
        set<int> order;
        for (int item : nums) {
            order.insert(item);
        }
        map<int, int> H;
        int idx = 0;
        for (int item : order) {
            H[item] = idx++;
        }
        seg.build(0, idx, 1);
        vector<int> res(len, 0);
        for (int i = len - 1; i >= 0; i--) {
            if (H[nums[i]] - 1 >= 0) {
                res[i] = seg.query(0, idx, 1, 0, H[nums[i]] - 1);
            }
            seg.update(0, idx, 1, H[nums[i]]);
        }
        return res;
    }
};

int main()
{
    return 0;
}
