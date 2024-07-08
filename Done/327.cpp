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

#define LL(x) (x << 1)
#define RR(x) ((x << 1) | 1)
#define MID(lft, rht) ((lft + rht) / 2)

const int N = 3e5 + 5;
struct SegTree {
    int sum[N * 4];
    void build(int lft, int rht, int idx)
    {
        sum[idx] = 0;
        if (lft == rht) {
            return;
        }
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
            if (pos <= mid)
                update(lft, mid, LL(idx), pos);
            else
                update(mid + 1, rht, RR(idx), pos);
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
    int countRangeSum(vector<int>& nums, int lower, int upper)
    {
        int len = (int)nums.size();
        vector<LL> sum(len, 0);
        set<LL> order;
        for (int i = 0; i < len; i++) {
            sum[i] += nums[i];
            if (i > 0)
                sum[i] += sum[i - 1];
            order.insert(sum[i]);
            order.insert(sum[i] - lower);
            order.insert(sum[i] - upper);
        }
        order.insert(0);
        map<LL, int> H;
        int idx = 0;
        for (LL x : order) {
            H[x] = idx++;
        }

        int res = 0;
        seg.build(0, idx, 1);
        seg.update(0, idx, 1, H[0]);
        for (int i = 0; i < len; i++) {
            // cout<<H[0]<<" "<<" lower:"<<H[sum[i]-upper]<<" upper:"<<H[sum[i] -lower]<<endl;
            int tmp = seg.query(0, idx, 1, H[sum[i] - upper], H[sum[i] - lower]);
            res += seg.query(0, idx, 1, H[sum[i] - upper], H[sum[i] - lower]);
            // cout << i << " " << tmp << endl;
            seg.update(0, idx, 1, H[sum[i]]);
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> data;
    data.push_back(-2);
    data.push_back(5);
    data.push_back(-1);
    cout << s.countRangeSum(data, -2, 2) << endl;
    return 0;
}
