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
int cnt[N];
struct SegTree {
    int data[N * 4];
    void build(int lft, int rht, int idx)
    {
        memset(data, 0, sizeof(data));
    }
    void update(int lft, int rht, int idx, int pos, int val)
    {
        if (lft == rht) {
            data[idx] += val;
        } else {
            int mid = MID(lft, rht);
            if (pos <= mid)
                update(lft, mid, LL(idx), pos, val);
            else
                update(mid + 1, rht, RR(idx), pos, val);
            data[idx] += val;
        }
    }
    int query(int lft, int rht, int idx, int st, int ed)
    {
        if (st <= lft && rht <= ed) {
            return data[idx];
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
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries)
    {
        map<int, map<int, int>> H;
        memset(cnt, 0, sizeof(cnt));
        int len = (int)edges.size();
        for (int i = 0; i < len; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            if (x > y) {
                swap(x, y);
            }
            cnt[x]++;
            cnt[y]++;
            H[y][x]++;
        }

        seg.build(0, N - 1, 1);
        len = (int)queries.size();
        vector<int> res(len, 0);
        for (int i = 1; i <= n; i++) {
            for (auto [key, val] : H[i]) {
                seg.update(0, N - 1, 1, cnt[key], -1);
                seg.update(0, N - 1, 1, cnt[key] - val, 1);
            }
            for (int j = 0; j < len; j++) {
                int tmp = seg.query(0, N - 1, 1, max(0, queries[j] - cnt[i] + 1), N - 1);
                res[j] += tmp;
                //cout << i << " " << j << " " << tmp << endl;
            }
            for (auto [key, val] : H[i]) {
                seg.update(0, N - 1, 1, cnt[key], 1);
                seg.update(0, N - 1, 1, cnt[key] - val, -1);
            }
            seg.update(0, N - 1, 1, cnt[i], 1);
        }
        return res;
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    return 0;
}
