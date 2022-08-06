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

const int N = 1e5 + 5;

class Solution {
public:
    bool vis[N];
    bool dfs(vector<int>& edges, int cur, int target, map<int, int>& data, int depth) {
        data[cur] = depth;
        if (cur == target) {
            return true;
        }
        int nxt = edges[cur];
        if (nxt != -1 && vis[nxt] == 0) {
            vis[nxt] = 1;
            return dfs(edges, nxt, target, data, depth + 1);
        }
        return false;
    }

    int getRes(map<int, int>& H1, map<int, int>& H2) {
        int res = -1;
        int key = -1;
        for (map<int, int>::iterator it = H1.begin(); it != H1.end(); it++) {
            int cur = it->first;
            int dis1 = it->second;
            if (H2.find(cur) != H2.end()) {
                int dis2 = H2[cur];

                if (res == -1) {
                    res = max(dis1, dis2);
                    key = cur;
                } else {
                    if (res > max(dis1, dis2)) {
                        res = max(dis1, dis2);
                        key = cur;
                    } else if (res == max(dis1, dis2)) {
                        key = min(key, cur);
                    }

                }
            }
        }
        return key;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        map<int, int> H1;
        map<int, int> H2;
        memset(vis, 0, sizeof(vis));
        vis[node1] = 1;
        dfs(edges, node1, node2, H1, 0);
        memset(vis, 0, sizeof(vis));
        vis[node2] = 1;
        dfs(edges, node2, node1, H2, 0);
        cout<<"H1"<<endl;
        for (map<int, int>::iterator it = H1.begin(); it != H1.end(); it++) {
            cout<<"node:"<<(it->first)<<" dis:"<<(it->second)<<endl;
        }

        cout<<"H2"<<endl;
        for (map<int, int>::iterator it = H2.begin(); it != H2.end(); it++) {
            cout<<"node:"<<(it->first)<<" dis:"<<(it->second)<<endl;
        }
        return getRes(H1, H2);
    }
};

int main()
{
    return 0;
}


