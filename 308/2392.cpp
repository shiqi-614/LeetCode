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

const int N = 405;

struct Node {
    int index;
    int depth;
    Node() { }
    Node(int index, int depth)
        : index(index)
        , depth(depth)
    {
    }
    bool operator<(const Node& b) const
    {
        return depth < b.depth;
    }
    void print()
    {
        cout << "index:" << index << " depth:" << depth << endl;
    }
};

class Solution {
public:
    vector<int> getIdx(int k, vector<vector<int>>& condition)
    {
        int in[N];
        bool vis[N];
        memset(in, 0, sizeof(in));
        int n = (int)condition.size();
        vector<vector<int>> adj(N, vector<int>());
        for (int i = 0; i < n; i++) {
            int tmp1 = condition[i][0];
            int tmp2 = condition[i][1];
            in[tmp1]++;
            adj[tmp2].push_back(tmp1);
        }
        vector<int> dis(k + 1, 0);
        queue<int> que;
        for (int i = 1; i <= k; i++) {
            if (in[i] == 0) {
                que.push(i);
                vis[i] = 1;
                dis[i] = 1;
            }
        }

        while (!que.empty()) {
            int top = que.front();
            que.pop();
            vis[top] = 0;
            int len = (int)adj[top].size();
            if (dis[top] > k) {
                vector<int> data(0, 0);
                return data;
            }
            for (int i = 0; i < len; i++) {
                int nxt = adj[top][i];
                if (dis[nxt] < dis[top] + 1) {
                    dis[nxt] = dis[top] + 1;
                    if (vis[nxt] == 0) {
                        vis[nxt] = 1;
                        que.push(nxt);
                    }
                }
            }
        }
        vector<Node> order;
        for (int i = 1; i <= k; i++) {
            order.push_back(Node(i, dis[i]));
        }
        sort(order.begin(), order.end());
        vector<int> data(k + 1, 0);
        for (int i = 1; i <= k; i++) {
            order[i - 1].print();
            data[order[i - 1].index] = i;
        }
        return data;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions)
    {
        int n = (int)rowConditions.size();
        int m = (int)colConditions.size();
        cout << "row" << endl;
        vector<int> row = getIdx(k, rowConditions);
        cout << "col" << endl;
        vector<int> col = getIdx(k, colConditions);
        if ((int)row.size() == 0 || (int)col.size() == 0) {
            return vector<vector<int>>(0, vector<int>(0, 0));
        }
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 1; i <= k; i++) {
            cout << i << " row:" << row[i] << " col:" << col[i] << endl;
            res[row[i]][col[i]] = i;
        }
        return res;
    }
};

int main()
{
    return 0;
}
