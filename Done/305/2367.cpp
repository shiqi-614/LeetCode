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
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int len = (int)nums.size();
        set<int> H;
        for (int i = 0; i < len; i++) {
            H.insert(nums[i]);
        }
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            int a = nums[i];
            int b = a + diff;
            int c = b + diff;
            if (H.find(b) != H.end() && H.find(c) != H.end()) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    return 0;
}


