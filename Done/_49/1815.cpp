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
    int batchSize;
    map<LL, int> dp;
    int dfs(int sum, LL state)
    {
        if (state <= 0) {
            return 0;
        } else {
            if (dp.find(state) != dp.end()) {
                return dp[state];
            }
            dp[state] = 0;
            int mx = 0;
            for (int i = batchSize - 1; i >= 1; i--) {
                int remain = ((state >> (i * 5)) % 32);
                if (remain > 0) {
                    mx = max(mx, dfs((sum + i) % batchSize, state - (1LL << (i * 5))) + (sum == 0));
                }
            }
            dp[state] = mx;
            return mx;
        }
    }
    int maxHappyGroups(int batchSize, vector<int>& groups)
    {
        this->dp.clear();
        this->batchSize = batchSize;
        int len = (int)groups.size();
        LL state = 0;
        int res = 0;
        for (int i = 0; i < len; i++) {
            int tmp = groups[i] % batchSize;
            if (tmp == 0) {
                res++;
            } else {
                state += (1LL << (tmp * 5));
            }
        }
        return res + dfs(0, state);
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    //
    Solution s;
    vector<int> data;
    // int tmp[] = { 3, 1, 3, 3, 5, 6, 1, 1, 9, 10, 3, 3, 3, 1, 1, 3, 3, 3, 19, 20, 1, 3, 3, 3, 3, 1, 1, 3, 3, 30 };
    // int tmp[] = { 287773481, 815094798, 356732984, 644469322, 543193620, 903158817, 274116865, 395252956, 363839119, 365378492, 122313059, 312690039, 252532812 };
    // int tmp[] = { 1, 2, 3, 4, 5, 6 };
    // int len = (int)sizeof(tmp) / sizeof(int);
    // for (int i = 0; i < len; i++) {
    // data.push_back(tmp[i]);
    // }
    // cout << s.maxHappyGroups(3, data) << endl;
    data.clear();

    int tmp2[] = { 145326640, 622724151, 591814792, 827053040, 111964428, 344376875, 42023891, 436582274, 78590835, 408269112, 930041188, 846233596, 158192647, 889601516, 134236253, 366035866, 123146762 };
    int len2 = (int)sizeof(tmp2) / sizeof(int);
    for (int i = 0; i < len2; i++) {
        data.push_back(tmp2[i]);
    }
    cout << s.maxHappyGroups(7, data) << endl;
    // cout << s.maxHappyGroups(9, data) << endl;

    return 0;
}
