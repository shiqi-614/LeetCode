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
    int x;
    int y;
    int idx;
    Node() { }
    Node(int x, int y, int idx)
        : x(x)
        , y(y)
        , idx(idx)
    {
    }
    bool operator<(const Node& b) const
    {
        return x < b.x;
    }
    void print()
    {
        cout << x << " " << y << " " << idx << endl;
    }
};

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points)
    {
        int len = (int)points.size();
        vector<Node> data1;
        vector<Node> data2;
        for (int i = 0; i < len; i++) {
            int x = points[i][0] + points[i][1];
            int y = points[i][1] - points[i][0];
            data1.push_back(Node(x, y, i));
            data2.push_back(Node(y, x, i));
        }

        sort(data1.begin(), data1.begin());
        sort(data2.begin(), data2.begin());
        for (int i = 0; i < len; i++) {
            data1[i].print();
        }
        cout << endl;
        for (int i = 0; i < len; i++) {
            data1[i].print();
        }
        set<int> candidate;
        candidate.insert(data1[0].idx);
        candidate.insert(data1[1].idx);
        candidate.insert(data1[len - 1].idx);
        candidate.insert(data1[len - 2].idx);
        candidate.insert(data2[0].idx);
        candidate.insert(data2[1].idx);
        candidate.insert(data2[len - 1].idx);
        candidate.insert(data2[len - 2].idx);
        int res = (1 << 30);
        for (set<int>::iterator it1 = candidate.begin(); it1 != candidate.end(); it1++) {
            int mx = 0;
            cout << (*it1) << endl;
            for (set<int>::iterator it2 = candidate.begin(); it2 != candidate.end(); it2++) {
                if (it1 != it2) {
                    for (set<int>::iterator it3 = candidate.begin(); it3 != candidate.end(); it3++) {
                        if (it2 != it3 && it1 != it3) {
                            int idx1 = *it2;
                            int idx2 = *it3;
                            int tmp = abs(points[idx1][0] - points[idx2][0]) + abs(points[idx1][1] - points[idx2][1]);
                            mx = max(mx, tmp);
                        }
                    }
                }
            }
            res = min(res, mx);
        }
        return res;
    }
};
int main()
{
    return 0;
}
