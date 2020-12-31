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
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> order;
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) if (nums[i] % 2) {
            order.push_back(i);
        }
        if (order.size() < k) return 0;
        len = (int)order.size();
        int res = 0;
        for (int i = k - 1; i < len; i++) {
            int lft = 0;
            int rht = 0;
            if (i - k + 1 > 0) lft = order[i - k + 1] - order[i - k];
            else if (i - k + 1 == 0) lft = order[i - k + 1];
            if (i + 1 < len) rht = order[i + 1] - order[i];
            else if (i + 1 == len) rht = len - order[i];
            res += lft * rht;
        }
        return res;
    }
};

int main() {
    return 0;
}

