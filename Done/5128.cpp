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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int N = 1e4 + 5;
class Solution {
public:
    int fa[N];
    int findFa(int x) {
        if (fa[x] != x) return fa[x] = findFa(fa[x]);
        else return x;
    }

    void unin(int x, int y) {
        if (findFa(x) != findFa(y)) {
            fa[findFa(x)] = findFa(y);
        }
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int> >& queries) {
        vector<vector<int> > adj(n + 1, vector<int>());
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            for (int j = 1; j * j <= i; j++) if (i % j == 0) {
                adj[j].push_back(i);
                if (i / j != j) adj[i / j].push_back(i);
            }
        }
        for (int i = threshold + 1; i <= n; i++) {
            int len = (int)adj[i].size();
            for (int j = 0; j + 1 < len; j++) {
                unin(adj[i][j], adj[i][j + 1]);
            }
        }

        vector<bool> res;
        int len = (int)queries.size();
        for (int i = 0; i < len; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (findFa(x) == findFa(y)) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};

int main()
{
}

