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
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int len = (int)nums.size();
        vector<int> res(len, -1);
        stack<int> st;
        for (int i = 0; i < len * 2; i++) {
            if (st.empty()) {
                st.push(i % len);
            } else {
                while (!st.empty() && nums[st.top() % len] < nums[i % len]) {
                    int idx = st.top();
                    //cout << "idx:" << idx << " val:" << nums[idx % len] << endl;
                    st.pop();
                    res[idx % len] = nums[i % len];
                }
                st.push(i % len);
            }
        }
        return res;
    }
};

int main()
{
    //int tmp[] = { 1, 2, 1 };
    //int tmp[] = { 5, 4, 3, 2, 1 };
    int tmp[] = { 1, 2, 3, 2, 1 };
    //int tmp[] = { 1, 8, -1, -100, -1, 222, 1111111, -111111 };
    vector<int> data;
    for (int i = 0; i < (int)sizeof(tmp) / sizeof(int); i++) {
        data.push_back(tmp[i]);
    }
    Solution s;
    vector<int> res = s.nextGreaterElements(data);
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
