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

class Solution {
public:
    vector<int> getOrder(int a) {
        vector<int> order;
        while(a>1) {
            order.push_back(a);
            a/=2;
        }
        reverse(order.begin(), order.end());
        return order;
    }
    int getRes(int a, int b) {
        if (a > b) swap(a, b);
        vector<int> orderA = getOrder(a);;
        vector<int> orderB = getOrder(b);
        int len = (int)orderA.size();
        int res = -1;
        for (int i = 0; i < len; i++) {
            if (orderA[i] != orderB[i]) {
                res = i;
                break;
            }
        }
        if (res == -1) {
            return orderB.size() - orderA.size() + 1;
        } else {
            return (orderB.size() - res) + (orderA.size() - res) + 1;
        }

    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int len = (int)queries.size();
        vector<int> res;
        for (int i = 0; i < len; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            res.push_back(getRes(a, b));
        }
        return res;
    }
};
int main()
{
    return 0;
}


