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
    vector<int> singleNumbers(vector<int>& nums) {
        int len = (int)nums.size();
        int mask = 0;
        for (int i = 0; i < len; i++) {
           mask ^= nums[i]; 
        }

        int tmp = mask & (-mask);
        int a = 0;
        int b = 0;
        vector<int> res;
        for (int i = 0; i < len; i++) {
            if (tmp & nums[i]) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }

        res.push_back(a);
        res.push_back(b);
        return res;

    }
};

int main() {
    return 0;
}

