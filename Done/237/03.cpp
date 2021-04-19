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

struct TaskNode {
    LL time;
    LL idx;
    LL cost;
    TaskNode() { }
    TaskNode(LL time, LL idx, LL cost)
        : time(time)
        , idx(idx)
        , cost(cost)
    {
    }
    bool operator<(const TaskNode& B) const
    {
        if (cost != B.cost) {
            return cost > B.cost;
        } else {
            return idx > B.idx;
        }
    }
};

struct QueNode {
    LL time;
    LL idx;
    LL cost;
    QueNode() { }
    QueNode(LL time, LL idx, LL cost)
        : time(time)
        , idx(idx)
        , cost(cost)
    {
    }
    bool operator<(const QueNode& B) const
    {
        if (time != B.time) {
            return time > B.time;
        } else {
            return idx > B.idx;
        }
    }
};
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks)
    {
        LL cpu = 0;
        int len = (int)tasks.size();
        priority_queue<QueNode> que1;
        priority_queue<TaskNode> que2;
        for (int i = 0; i < len; i++) {
            que1.push(QueNode(tasks[i][0], i, tasks[i][1]));
        }

        vector<int> res;
        while (1) {
            bool flag = 0;
            if (!que2.empty()) {
                TaskNode top = que2.top();
                que2.pop();
                res.push_back(top.idx);
                cpu += top.cost;
                flag = 1;
            }
            while (!que1.empty() && cpu >= que1.top().time) {
                QueNode top = que1.top();
                que1.pop();
                que2.push(TaskNode(top.time, top.idx, top.cost));
                flag = 1;
            }
            if (!flag) {
                if (!que1.empty()) {
                    cpu = que1.top().time;
                } else {
                    break;
                }
            }
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
