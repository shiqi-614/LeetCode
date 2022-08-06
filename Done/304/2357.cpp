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
    int minimumOperations(vector<int>& nums) {
        int len = (int)nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        while(1) {
            int tmp = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] > 0 && tmp == 0) {
                   tmp = nums[i]; 
                }
                nums[i]-=tmp;
            }
            if (tmp == 0) {
                return res;
            }
            res++;
            sort(nums.begin(), nums.end());
        }
        return res;
    }
};

int main()
{
    return 0;
}


