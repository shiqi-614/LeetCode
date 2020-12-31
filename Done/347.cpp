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
    int value;
    int count;
    Node() {}
    Node(int value, int count) : value(value), count(count) { }
    bool operator<(const Node &b) const {
        return count < b.count;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> H;
        for (int i = 0; i < (int)nums.size(); i++) {
            H[nums[i]]++;
        }

        priority_queue<Node> que;
        map<int, int>::iterator it;
        for (it = H.begin(); it != H.end(); it++) {
            if (que.size() < k) {
               que.push(Node(it->first, it->second));
            } else {
                if (que.top().count < it->second) {
                    que.pop();
                    que.push(Node(it->first, it->second));
                }
            }
        }
        vector<int> res;
        while(!que.empty()) {
            res.push_back(que.top().value);
            que.pop();
        }
        return res;
    }
};

int main()
{
    return 0;
}

