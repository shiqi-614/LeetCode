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

const int N = 105;

struct Node {
    long long st;
    long long ed;
    long long room;
    Node() {}
    Node(long long st, long long ed, long long room) : st(st), ed(ed), room(room) {}
    bool operator<(const Node &b) const {
        if (ed != b.ed) {
            return ed > b.ed;
        } else {
            return room > b.room;
        }
    }
};

struct Order {
    long long st;
    long long ed;
    Order() {}
    Order(long long st, long long ed) : st(st), ed(ed) {}
    bool operator<(const Order& b) const {
        return st < b.st;
    }
};

class Solution {
public:
    bool vis[N];
    int cnt[N];
    int mostBooked(int n, vector<vector<int>>& meetings) {
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        int len = (int)meetings.size();
        vector<Order> order;
        for (int i = 0; i < len; i++) {
            int st = meetings[i][0];
            int ed = meetings[i][1];
            order.push_back(Order(st, ed));
        }
        sort(order.begin(), order.end());
        //for (int i = 0; i < len; i++) {
          //  order[i].print();
        //}

        priority_queue<Node> que;
        for (int i = 0; i < len; i++) {
            long long st = order[i].st;
            long long ed = order[i].ed;
            while (que.size() > 0) {
                Node top = que.top();
                if (top.ed <= st) {
                    vis[top.room] = 0;
                    que.pop();
                   // cout<<"pop"<<endl;
                    //top.print();
                } else {
                    break;
                }
            }
            if (que.size() <  n)  {
                for (int j = 0; j < n; j++) {
                    if (vis[j] == 0) {
                        vis[j] = 1;
                        que.push(Node(st, ed, j));
                 //       cout<<"add empty"<<endl;
                        //Node(st, ed, j).print();
                        vis[j] = 1;
                        cnt[j]++;
                        break;
                    }
                }
            } else {
                Node top = que.top(); que.pop();
               // cout<<"top:"<<endl;
                //top.print();
                long long dis = ed - st;
                que.push(Node(top.ed, top.ed + dis, top.room));
             //   cout<<"add delay"<<endl;
           //     cout<<"org st:"<<st<<" ed:"<<ed<<endl;
                //Node(top.ed, top.ed + dis, top.room).print();
                cnt[top.room]++;
                vis[top.room] = 1;
            }
        }

        int res = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {

            //cout<<cnt[i]<<" ";
            if (mx < cnt[i]) {
                mx = cnt[i];
                res = i;
            }
        }
        //cout<<endl;
        return res;
    }
};


