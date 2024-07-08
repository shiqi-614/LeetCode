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

typedef long long LL;
typedef pair<int, int> PII;

struct Node {
    int dur;
    int last;
    Node() { }
    Node(int dur, int last)
        : dur(dur)
        , last(last)
    {
    }
    bool operator<(const Node& b) const
    {
        if (last != b.last)
            return last < b.last;
        else
            return dur > b.dur;
    }
};
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses)
    {
        int len = (int)courses.size();
        vector<Node> order;
        for (int i = 0; i < len; i++) {
            if (courses[i][0] <= courses[i][1]) {
                order.push_back(Node(courses[i][0], courses[i][1]));
            }
        }

        sort(order.begin(), order.end());
        priority_queue<int, vector<int>, greater<>> que;
        int sum = 0;
        int res = 0;
        len = (int)order.size();
        for (int i = 0; i < len; i++) {
            while (1) {
                if (sum + order[i].dur > order[i].last) {
                    if (!que.empty() && que.top() > order[i].dur) {
                        sum -= que.top();
                        que.pop();
                    }
                }
                if (que.empty() || sum + order[i].dur <= order[i].last) {
                    break;
                }
            }
            if (sum + order[i].dur <= order[i].last) {
                que.push(order[i].dur);
                sum += order[i].dur;
            }
            res = max(res, (int)que.size());
        }
        return res;
    }
};

int main()
{
    return 0;
}
