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
#include <pthread.h>
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

struct Node {
    int pos;
    bool type;
    int idx;
    Node() { }
    Node(int pos, bool type, int idx)
        : pos(pos)
        , type(type)
        , idx(idx)
    {
    }
    bool operator<(const Node& b)
    {
        if (pos != b.pos) {
            return pos < b.pos;
        } else {
            return type < b.type;
        }
    }
};

const int N = 1e4 + 5;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        bool vis[N];
        memset(vis, 0, sizeof(vis));
        int len = (int)points.size();
        vector<Node> order;
        for (int i = 0; i < len; i++) {
            order.push_back(Node(points[i][0], 0, i));
            order.push_back(Node(points[i][1], 1, i));
        }
        sort(order.begin(), order.end());
        //for (int i = 0; i < (int)order.size(); i++) {
        //cout << order[i].pos << " type:" << order[i].type << " idx:" << order[i].idx << endl;
        //}
        queue<int> que;
        int res = 0;
        for (int i = 0; i < (int)order.size(); i++) {
            //            cout << order[i].pos << " type:" << order[i].type << " idx:" << order[i].idx << endl;
            if (order[i].type == 0) {
                que.push(order[i].idx);
            } else if (order[i].type == 1) {
                if (vis[order[i].idx] == 0) {
                    bool flag = 0;
                    while (!que.empty()) {
                        int tmp = que.front();
                        que.pop();
                        if (!vis[tmp]) {
                            vis[tmp] = 1;
                            //                            cout << "set idx:" << tmp << endl;
                            flag = 1;
                        }
                    }
                    if (flag) {
                        res++;
                        //                        cout << "add res:" << res << endl;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> data;
    vector<int> p1;
    p1.push_back(10);
    p1.push_back(16);
    vector<int> p2;
    p2.push_back(2);
    p2.push_back(8);
    vector<int> p3;
    p3.push_back(1);
    p3.push_back(6);
    vector<int> p4;
    p4.push_back(7);
    p4.push_back(12);
    data.push_back(p1);
    data.push_back(p2);
    data.push_back(p3);
    data.push_back(p4);
    cout << s.findMinArrowShots(data) << endl;
    return 0;
}
