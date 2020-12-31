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
#define RR(x) ((x<<1)|1)
#define MID(x, y) (x + ((y - x) >> 1))


typedef long long LL;
typedef pair<int,int> PII;

const int N = 20005;

struct SegTree {
    PII node[N*4];

    void build(int lft, int rht, int idx, vector<int>& arr) {
        if (lft == rht) {
            node[idx] = MP(arr[lft], 1);
        } else {
            int mid = MID(lft, rht);
            build(lft, mid, LL(idx), arr);
            build(mid + 1, rht, RR(idx), arr);
            node[idx] = merge(node[LL(idx)], node[RR(idx)]);
        }
    }

    PII merge(PII res1, PII res2) {
        if (res1.first == res2.first) {
            return MP(res1.first, res1.second + res2.second);
        } else {
            return MP(res1.second > res2.second ? res1.first : res2.first, abs(res1.second - res2.second));
        }

    }

    PII query(int lft, int rht, int idx, int st, int ed) {
        cout<<lft<<" "<<rht<<" "<<idx<<" st:"<<st<<" "<<ed<<endl;
        if (st <= lft && rht <= ed) {
            return node[idx];
        } else {
            int mid = MID(lft, rht);
            PII res1 = MP(0, -1);
            PII res2 = MP(0, -1);
            if (st <= mid) res1 = query(lft, mid, LL(idx), st, ed);
            if (ed >= mid + 1) res2 = query(mid + 1, rht, RR(idx), st, ed);
            if (res1.second == -1) {
                return res2;
            } else if (res2.second == -1) {
                return res1;
            } else {
                return merge(res1, res2);
            }
        }
        
    }
};
class MajorityChecker {
public:
    int len;
    SegTree tree;
    map<int, vector<int> > H;
    MajorityChecker(vector<int>& arr) {
        int len = (int)arr.size();
        tree.build(0, len - 1, 1, arr);
        for (int i = 0; i < len; i++) {
            if (H.find(arr[i]) == H.end()) {
                H.insert(MP(arr[i], vector<int>()));
            } 
            H[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        PII res = tree.query(0, len - 1, 1, left, right);
        int key = res.first;
        cout<<"get res from tree:"<<res.first<<" "<<res.second<<endl;
        auto idx1 = lower_bound(H[key].begin(), H[key].end(), left);
        auto idx2 = upper_bound(H[key].begin(), H[key].end(), right);
        cout<<"count:"<<(idx2 - idx1)<<endl;
        if (idx2 - idx1 >= threshold) {
            return key;
        }
        return -1;
    }
};

int main() {
    return 0;
}

