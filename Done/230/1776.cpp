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

#define INF (1 << 30)
struct Node {
    int pos;
    int v;
    Node() { }
    Node(int pos, int v)
        : pos(pos)
        , v(v)
    {
    }
    void print()
    {
        cout << "pos:" << pos << " v:" << v << endl;
    }
};
class Solution {
public:
    double getMeetTime(Node current, Node next)
    {
        //cout << "next:" << endl;
        //next.print();
        //cout << "current:" << endl;
        //current.print();
        if (current.v <= next.v)
            return INF;
        return 1.0 * (next.pos - current.pos) / (current.v - next.v);
    }
    vector<double> getCollisionTimes(vector<vector<int>>& cars)
    {
        int len = (int)cars.size();
        vector<int> carGroup(len, 0);
        vector<double> res(len, -1);

        int minSpeed = INF;
        int minPos = -1;
        for (int i = len - 1; i >= 0; i--) {
            if (minSpeed >= cars[i][1]) {
                minSpeed = cars[i][1];
                minPos = i;
            }
            carGroup[i] = minPos;
        }
        //cout << "group" << endl;
        //for (int i = 0; i < len; i++)
        //cout << carGroup[i] << " ";
        //cout << endl;
        stack<Node> que;
        for (int i = len - 1; i >= 0; i--) {
            if (carGroup[i] == i) {
                while (!que.empty()) {
                    que.pop();
                }
            }
            Node current = Node(cars[i][0], cars[i][1]);
            while (!que.empty()) {
                Node top1 = que.top();
                que.pop();
                //cout << "top1" << endl;
                //top1.print();
                //cout << "current" << endl;
                //current.print();

                if (top1.v >= current.v) {
                    continue;
                }
                if (!que.empty()) {
                    Node top2 = que.top();
                    que.pop();
                    //cout << "top2" << endl;
                    //top2.print();
                    double t1 = getMeetTime(current, top1);
                    double t2 = getMeetTime(current, top2);
                    //cout << "i:" << i << " t1:" << t1 << " t2:" << t2 << endl;
                    if (t1 > t2) {
                        que.push(top2);
                    } else {
                        que.push(top2);
                        que.push(top1);
                        res[i] = t1;
                        break;
                    }
                } else {
                    que.push(top1);
                    res[i] = getMeetTime(current, top1);
                    break;
                }
            }
            que.push(current);
            //cout << "i:" << i << " que size:" << que.size() << endl;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> data;
    vector<int> tmp1;
    vector<int> tmp2;
    vector<int> tmp3;
    vector<int> tmp4;
    //tmp1.push_back(1);
    //tmp1.push_back(2);
    //tmp2.push_back(2);
    //tmp2.push_back(1);
    //tmp3.push_back(4);
    //tmp3.push_back(3);
    //tmp4.push_back(7);
    //tmp4.push_back(2);
    tmp1.push_back(3);
    tmp1.push_back(4);
    tmp2.push_back(5);
    tmp2.push_back(4);
    tmp3.push_back(6);
    tmp3.push_back(3);
    tmp4.push_back(9);
    tmp4.push_back(1);

    data.push_back(tmp1);
    data.push_back(tmp2);
    data.push_back(tmp3);
    data.push_back(tmp4);
    Solution s;
    vector<double> res = s.getCollisionTimes(data);
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
