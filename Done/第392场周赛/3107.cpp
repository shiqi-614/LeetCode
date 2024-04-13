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

#define PB push
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k)
    {
        priority_queue<LL> small;
        priority_queue<LL, vector<LL>, greater<LL>> big;
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            small.push(nums[i]);
        }

        while ((int)small.size() != len / 2) {
            LL tmp = small.top();
            small.pop();
            big.push(tmp);
        }

        LL res = 0;
        while (1) {
            LL tmp = big.top();
            big.pop();
            cout << "cur:" << tmp << endl;
            if (tmp == k) {
                return res;
            } else if (tmp > k) {
                res += abs(tmp - k);
                small.push(k);
                tmp = small.top();
                cout << " get small value:" << tmp << endl;
                small.pop();
                big.push(tmp);
            } else if (tmp < k) {
                res += abs(tmp - k);
                cout << " big push:" << k << endl;
                big.push(k);
            }
        }
        return res;
    }
};

int main()
{
    // 2, 5, 5, 6, 8
}
