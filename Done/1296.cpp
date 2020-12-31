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

typedef long long LL;
typedef pair<int,int> PII;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> H;
        map<int, int> order;
        int cnt = 0;
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            H[nums[i]]++;
            if (order.find(nums[i]) == order.end()) {
                order.insert(make_pair(nums[i], cnt++));
            }
        }

        map<int, int>::iterator it;
        queue<PII> que;
        int sum = 0;
        for (it = H.begin(); it != H.end(); it++) {
            if (it->second < sum) {
                cout<<"middle: "<<it->first<<" "<<it->second<<endl;
                return false;
            }
            if (!que.empty() && it->first - que.front().first != order[it->first] - order[que.front().first]) {
                return false;
            }
            if (que.empty() || sum < it->second) {
                que.push(make_pair(it->first, it->second - sum));
                sum = it->second;
            }
            if (que.front().first + k - 1 <= it->first) {
                sum -= que.front().second;
                que.pop();
            }
            cnt++;
        }
        if (!que.empty()) {
            cout<<"que not empty"<<endl;
            return false;
        }
        return true;
    }
};

int main() {
    return 0;
}

