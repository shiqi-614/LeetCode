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

const int N = 35;

class Solution {
public:
    vector<int> data;
    int dp[N][2][2];
    void getData(int n)
    {
        if (n == 0)
            data.push_back(0);
        else {
            while (n) {
                int tmp = n % 2;
                n = n / 2;
                data.push_back(tmp);
            }
        }
    }
    // type 0 small
    // type 1 equal
    int dfs(int idx, int value, int type)
    {
        if (idx == 0) {
            //cout << "idx:" << idx << " value:" << value << " type:" << type << " res:" << 1 << endl;
            return 1;
        } else {
            int& res = dp[idx][value][type];
            if (res != -1)
                return res;

            res = 0;
            if (type == 0) {
                if (value == 0) {
                    res += dfs(idx - 1, 0, type);
                    res += dfs(idx - 1, 1, type);
                } else {
                    res += dfs(idx - 1, 0, type);
                }
            } else {
                int pre = data[idx - 1];
                for (int i = 0; i <= 1; i++) {
                    if (value == 1 && i == 1)
                        continue;
                    if (type == 1 && i > pre)
                        continue;
                    res += dfs(idx - 1, i, type == 0 ? type : (i < pre ? 0 : 1));
                }
            }
            //cout << "idx:" << idx << " value:" << value << " type:" << type << " res:" << res << endl;
            return res;
        }
    }
    int largestPalindrome(int n)
    {
        data.clear();
        memset(dp, -1, sizeof(dp));
        getData(n);
        int len = (int)data.size() - 1;
        int res = 0;
        if (data[len] == 0)
            res += dfs(len, 0, 1);
        else {
            res += dfs(len, 0, 0);
            res += dfs(len, 1, 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.largestPalindrome(5) << endl;
    cout << s.largestPalindrome(1) << endl;
    return 0;
}
