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

struct Node {
    double pass;
    double total;
    Node() { }
    Node(int pass, int total)
        : pass(pass)
        , total(total)
    {
    }
    bool operator<(const Node& B) const
    {
        double tmp1 = (pass + 1) / (total + 1) - pass / total;
        double tmp2 = (B.pass + 1) / (B.total + 1) - B.pass / B.total;
        return tmp1 > tmp2;
    }
};
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        int len = (int)classes.size();
        priority_queue<Node> que;
        for (int i = 0; i < len; i++) {
            que.push(Node(classes[i][0], classes[i][1]));
        }
        while (extraStudents--) {
            Node top = que.top();
            que.pop();
            top.pass++;
            top.total++;
            que.push(top);
        }
        double res = 0;
        while (!que.empty()) {
            Node top = que.top();
            que.pop();
            res += (top.pass) / top.total;
        }
        res /= len;
        return res;
    }
};
int main()
{
    vector<Node> data;
    data.push_back(Node(2, 4));
    data.push_back(Node(3, 9));
    data.push_back(Node(4, 5));
    data.push_back(Node(2, 10));
    for (int j = 0; j < 4; j++) {
        int idx = -1;
        double mx = 0;
        for (int i = 0; i < (int)data.size(); i++) {
            int pass = data[i].pass;
            int total = data[i].total;
            double tmp = (1.0 * (pass + 1) / (total + 1)) - (1.0 * (pass) / (total));
            if (tmp > mx) {
                mx = tmp;
                idx = i;
            }
        }
        cout << data[idx].pass << " " << data[idx].total << endl;
        data[idx].pass++;
        data[idx].total++;
    }
    double sum = 0;
    for (int i = 0; i < (int)data.size(); i++) {
        sum += 1.0 * (data[i].pass) / (data[i].total);
    }
    sum /= (int)data.size();
    cout << "res:" << sum << endl;
    return 0;
}
