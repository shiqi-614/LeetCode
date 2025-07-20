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

typedef pair<int, int> PII;
typedef long long LL;

const int N = 1e5 + 5;
class Solution {
    public:
        int fa[N];
        int find_fa(int u) {
            if (fa[u] != u) {
                fa[u] = find_fa(fa[u]);
            }
            return fa[u];
        }
        void unin(int u, int v) {
            int faU = find_fa(u);
            int faV = find_fa(v);
            fa[faV] = faU;
        }
        int maxStability(int n, vector<vector<int>>& edges, int k) {
            for (int i = 0; i < n; i++) {
                fa[i] = i;
            }
            sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>&b) {
                    if (a[3] != b[3]) {
                    return a[3] > b[3];
                    } else {
                    return a[2] > b[2];
                    }
                    });

            int mi_must = 1<<30;
            priority_queue<int, vector<int>, greater<int>> min_heap;
            int len = (int)edges.size();
            for (int i = 0; i < len; i++) {
                vector<int>& edge = edges[i];
                int u = edge[0];
                int v = edge[1];
                int s = edge[2];
                int must = edge[3];
                int faU = find_fa(u);
                int faV = find_fa(v);
                if (must) {
                    if (faU == faV) {
                        return -1;
                    } else {
                        unin(faU, faV);
                        mi_must = min(mi_must, s);
                    }
                } else {
                    if (faU != faV) {
                        unin(faU, faV);
                        min_heap.push(s);
                    }
                }
            }
            //cout<<"p1"<<endl;
            for (int i = 0; i < n; i++) {
                if (find_fa(i) != find_fa(0)) {
                    return -1;
                }
            }
            //cout<<"p2"<<endl;
            while(k-- && min_heap.size() > 0) {
                int mi = min_heap.top();
                min_heap.pop();
                mi = mi*2;
                mi_must = min(mi, mi_must);
                //min_heap.push(mi);
            }
            //cout<<"p3"<<endl;
            if (min_heap.size() > 0) {
                return min(mi_must, min_heap.top());
            } else {
                return mi_must;
            }
        }
};

int main()
{
    return 0;
}

