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

#define MID(lft, rht) (lft + ((rht - lft) >> 1))
#define LL(x) (x << 1)
#define RR(x) ((x << 1) | 1)

const int N = 1e5 + 5;
struct Node {
    int pos;
    int val;
    Node() { }
    Node(int pos, int val)
        : pos(pos)
        , val(val)
    {
    }
    bool operator<(const Node& B) const
    {
        return val > B.val;
    }
};
struct SegTree {
    Node mx[N * 4];
    void build(int lft, int rht, int idx, vector<int>& data)
    {
        if (lft == rht) {
            mx[idx] = Node(lft, data[lft]);
        } else {
            int mid = MID(lft, rht);
            build(lft, mid, LL(idx), data);
            build(mid + 1, rht, RR(idx), data);
            if (mx[LL(idx)].val > mx[RR(idx)].val) {
                mx[idx] = mx[LL(idx)];
            } else {
                mx[idx] = mx[RR(idx)];
            }
        }
    }
    Node query(int lft, int rht, int idx, int st, int ed)
    {
        if (st <= lft && rht <= ed) {
            return mx[idx];
        } else {
            int mid = MID(lft, rht);
            Node mx1 = Node(-1, -1);
            Node mx2 = Node(-1, -1);
            if (st <= mid)
                mx1 = query(lft, mid, LL(idx), st, ed);
            if (ed > mid)
                mx2 = query(mid + 1, rht, RR(idx), st, ed);
            if (mx1.val > mx2.val) {
                return mx1;
            } else {
                return mx2;
            }
        }
    }
};

class Solution {
public:
    SegTree seg1;
    SegTree seg2;
    int len1;
    int len2;
    int K;
    vector<int> nums1;
    vector<int> nums2;
    vector<int> merge(vector<Node>& order1, vector<Node>& order2)
    {
        int idx1 = 0;
        int idx2 = 0;
        vector<int> res;
        while (idx1 < (int)order1.size() || idx2 < (int)order2.size()) {
            if (idx1 < (int)order1.size() && idx2 < (int)order2.size()) {
                if (order1[idx1].val > order2[idx2].val) {
                    res.push_back(order1[idx1].val);
                    idx1++;
                } else if (order1[idx1].val < order2[idx2].val) {
                    res.push_back(order2[idx2].val);
                    idx2++;
                } else {
                    if (compareUntilDifference(order1, order2, idx1, idx2)) {
                        res.push_back(order1[idx1].val);
                        idx1++;
                    } else {
                        res.push_back(order1[idx2].val);
                        idx2++;
                    }
                }
            } else if (idx1 < (int)order1.size()) {
                res.push_back(order1[idx1].val);
                idx1++;

            } else {
                res.push_back(order1[idx2].val);
                idx2++;
            }
        }
        return res;
    }

    bool compareUntilDifference(vector<Node>& order1, vector<Node>& order2, int idx1, int idx2)
    {
        while (idx1 < (int)order1.size()
            && idx2 < (int)order2.size()
            && order1[idx1].val == order2[idx2].val) {
            idx1++;
            idx2++;
        }

        if (idx1 >= (int)order1.size())
            return false;
        if (idx2 >= (int)order2.size())
            return true;
        return order1[idx1].val > order2[idx2].val;
    }
    void dfs(int lft1, int rht1, int lft2, int rht2, vector<Node>& order1, vector<Node>& order2)
    {
        cout << "lft1:" << lft1 << " rht1:" << rht1 << " lft2:" << lft2 << " rht2:" << rht2 << " K:" << this->K << endl;
        if (K < 0)
            return;
        if (lft1 > rht1 && lft2 > rht1) {
            return;
        }

        Node mx1 = Node(-1, -1);
        Node mx2 = Node(-1, -1);

        if (lft1 <= rht1) {
            mx1 = seg1.query(0, len1 - 1, 1, lft1, rht1);
        }
        if (lft2 <= rht2) {
            mx2 = seg2.query(0, len2 - 1, 1, lft2, rht2);
        }
        K--;
        if (mx1.val > mx2.val) {
            order1.push_back(mx1);
            dfs(mx1.pos + 1, rht1, lft2, rht2, order1, order2);
        } else if (mx1.val <= mx2.val) {
            order2.push_back(mx2);
            dfs(lft1, rht1, mx2.pos + 1, rht2, order1, order2);
        }
    }

    int getPrePos(int idx, vector<Node> order)
    {
        if (idx - 1 >= 0) {
            return order[idx - 1].pos + 1;
        } else {
            return 0;
        }
    }
    vector<Node> getData(int lft, int rht, vector<int> nums)
    {
        priority_queue<Node> que;
        for (int i = lft; i <= rht; i++) {
            que.push(Node(i, nums[i]));
        }
        vector<Node> data;
        while (!que.empty() && K--) {
            data.push_back(que.top());
            que.pop();
        }
        return data;
    }
    void mergeOrder(vector<Node>& newData, vector<Node>& data, int idx)
    {
        vector<Node> tmp(data.begin(), data.end());
        data.clear();
        for (int i = (int)tmp.size() - 1; i >= 0; i--) {
            data.push_back(tmp[i]);
            if (i == idx) {
                for (int j = 0; j < (int)newData.size(); j++) {
                    data.push_back(newData[j]);
                }
            }
        }
        reverse(data.begin(), data.end());
    }
    void dfs2(int idx1, int idx2, vector<Node>& order1, vector<Node>& order2)
    {
        if (K <= 0) {
            return;
        }
        if (idx1 >= 0 && idx2 >= 0) {
            if (order1[idx1].val < order2[idx2].val) {
                vector<Node> pos = getData(getPrePos(idx1, order1), order1[idx1].pos - 1, nums1);
                mergeOrder(pos, order1, idx1);
                idx1--;
            } else if (order1[idx1].val > order2[idx2].val) {
                vector<Node> pos = getData(getPrePos(idx2, order2), order2[idx2].pos - 1, nums2);
                mergeOrder(pos, order2, idx2);
                idx2--;
            } else {
                vector<Node> subOrder1;
                vector<Node> subOrder2;
                dfs(getPrePos(idx1, order1), order1[idx1].pos - 1, getPrePos(idx2, order2), order2[idx2].pos - 1, subOrder1, subOrder2);
                mergeOrder(subOrder1, order1, idx1);
                mergeOrder(subOrder2, order2, idx2);
                idx1--;
                idx2--;
            }
        } else if (idx1 >= 0) {
            vector<Node> pos = getData(getPrePos(idx1, order1), order1[idx1].pos - 1, nums1);
            mergeOrder(pos, order1, idx1);
            idx1--;
        } else if (idx2 >= 0) {
            vector<Node> pos = getData(getPrePos(idx2, order2), order2[idx2].pos - 1, nums2);
            mergeOrder(pos, order2, idx2);
        }
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
    {
        len1 = (int)nums1.size();
        len2 = (int)nums2.size();
        this->nums1 = nums1;
        this->nums2 = nums2;
        seg1.build(0, len1 - 1, 1, nums1);
        seg2.build(0, len2 - 1, 1, nums2);
        this->K = k;

        vector<Node> order1;
        vector<Node> order2;
        dfs(0, len1 - 1, 0, len2 - 1, order1, order2);
        if (K > 0) {
            dfs2((int)order1.size() - 1, (int)order2.size() - 1, order1, order2);
        }

        return merge(order1, order2);
    }
};

int main()
{
    Solution s;
    vector<int> data1;
    vector<int> data2;

    int tmp1[] = { 3, 4, 6, 5 };
    int tmp2[] = { 9, 1, 2, 5, 8, 3 };

    for (int i = 0; i < (int)sizeof(tmp1) / sizeof(int); i++) {
        data1.push_back(tmp1[i]);
    }

    for (int i = 0; i < (int)sizeof(tmp2) / sizeof(int); i++) {
        data2.push_back(tmp2[i]);
    }

    vector<int> res = s.maxNumber(data1, data2, 5);
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
