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
    int getGcd(int x, int y) {
        if (x % y == 0) {
            return y;
        } else return gcd(y, x % y);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int len = (int)numsDivide.size();
        int gcd = numsDivide[0];
        for (int i = 1; i < len; i++ ) {
            gcd = getGcd(gcd, numsDivide[i]);
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == gcd) {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    return 0;
}


