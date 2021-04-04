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
    int gcd(int x, int y)
    {
        if (x % y == 0) {
            return y;
        } else {
            return gcd(y, x % y);
        }
    }

    int countDifferentSubsequenceGCDs(vector<int>& nums)
    {
        int res = 0;
        int mx = *max_element(nums.begin(), nums.end());
        vector<bool> vis(mx + 1, 0);
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            vis[nums[i]] = 1;
        }

        for (int i = 1; i <= mx; i++) {
            int gcdRes = -1;
            for (int j = i * 2; j <= mx; j += i) {
                if (!vis[j]) {
                    continue;
                }
                if (gcdRes == -1) {
                    gcdRes = j;
                } else {
                    gcdRes = gcd(j, gcdRes);
                }
                if (gcdRes == i) {
                    vis[gcdRes] = 1;
                    break;
                }
            }
        }

        for (int i = 0; i <= mx; i++) {
            if (vis[i]) {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tmp[] = { 5, 15, 40, 5, 6 };
    int len = (int)sizeof(tmp) / sizeof(int);
    vector<int> data;
    for (int i = 0; i < len; i++) {
        data.push_back(tmp[i]);
    }
    Solution s;
    cout << s.countDifferentSubsequenceGCDs(data) << endl;
    return 0;
}
