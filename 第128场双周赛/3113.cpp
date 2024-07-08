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
    LL calc(LL cnt)
    {
        return cnt * (cnt - 1) / 2 + cnt;
    }
    long long numberOfSubarrays(vector<int>& nums)
    {
        nums.push_back(1e9 + 1);
        int len = (int)nums.size();
        stack<int> st;
        int idx = 0;
        LL res = 0;
        while (idx < len) {
            if (st.empty() || st.top() >= nums[idx]) {
                st.push(nums[idx]);
                idx++;
            } else {
                int tmp = st.top();
                st.pop();
                int cnt = 1;
                while (!st.empty() && tmp == st.top()) {
                    cnt++;
                    st.pop();
                }
                res += calc(cnt);
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
