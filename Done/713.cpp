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
    int calc(int st, int ed) {
        if (st >= ed) {
            return 0;
        } else {
            int num = ed - st;
            return num;
        }
    }

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int len = (int)nums.size();
        if (len == 0) {
            return 0;
        }
        int st = 0;
        int ed = 0;
        LL res = 0;
        LL product = 1;
        while(st < len) {
           while(ed < len && product * nums[ed] < k) {
               product *= nums[ed];
               ed++;
           }
           if (product < k) {
               res += calc(st, ed);
           }
           product /= nums[st];
           if (product == 0) product = 1;
           st++;
           if (ed < st) ed = st;
        }
        return res;
    }
};

int main() {
    vector<int> data;
    for (int i = 0; i < 4; i++) {
        data.push_back(1);
    }
    Solution s;
    cout<<s.numSubarrayProductLessThanK(data, 2)<<endl;
    return 0;
}

