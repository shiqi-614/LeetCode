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
    int beautySum(string s)
    {
        int cnt[30];
        int res = 0;
        int len = (int)s.length();
        for (int i = 0; i < len; i++) {
            memset(cnt, 0, sizeof(cnt));
            int idx = s[i] - 'a';
            cnt[idx]++;
            for (int j = i + 1; j < len; j++) {
                idx = s[j] - 'a';
                cnt[idx]++;
                int mi = INT_MAX;
                int mx = INT_MIN;
                for (int k = 0; k < 30; k++)
                    if (cnt[k]) {
                        mi = min(mi, cnt[k]);
                        mx = max(mx, cnt[k]);
                    }
                res += (mx - mi);
            }
        }
        return res;
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    Solution s;
    cout << s.beautySum("aabcb") << endl;

    return 0;
}
