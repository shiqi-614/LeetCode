#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

struct Node {
    int w;
    int h;
    Node() {}
    Node(int w, int h) : w(w), h(h) {}
    bool operator<(const Node &b) const {
        if (w != b.w) return w < b.w;
        else return h < b.h;
    }
};
class Solution {
public:
    int maxEnvelopes(vector<vector<int> >& envelopes) {
        int len = (int)envelopes.size();
        vector<Node> order;
        for (int i = 0; i < len; i++) {
            order.push_back(Node(envelopes[i][0], envelopes[i][1]));
        }
        sort(order.begin(), order.end());
        //for (int i = 0; i < len; i++) {
            //cout<<order[i].w<<" "<<order[i].h<<endl;
        //}

        vector<int> dp(len, 1);
        int res = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (order[i].h > order[j].h && order[i].w > order[j].w) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    return 0;
}

