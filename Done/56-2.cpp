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
    void getCnt(vector<int>& cnt, int num) {
        int idx = 0;
        while(num) {
            int tmp = num % 2;
            num = num >> 1;
            cnt[idx] += tmp;
            idx++;
        }
    }
    int singleNumber(vector<int>& nums) {
        vector<int> cnt(40, 0);
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            getCnt(cnt, nums[i]);
        }
        
        int res = 0;
        for (int i = 0; i < 40; i++) {
            if (cnt[i] % 3 == 1) {
                res |= (1<<i);
            } 
        }
        return res;
    }
};

int main() {
    return 0;
}

