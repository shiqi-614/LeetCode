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
    int findTheWinner(int n, int k)
    {
        int cnt = n;
        int cur = 0;
        vector<bool> vis(n, 1);
        while (cnt > 1) {
            int idx = 0;
            while (vis[cur] == 0) {
                cur = (cur + 1) % n;
            }
            int tmp = k;
            while (1) {
                if (vis[cur] == 1) {
                    tmp--;
                }
                if (tmp == 0) {
                    vis[cur] = 0;
                    cnt--;
                    break;
                }
                cur = (cur + 1) % n;
            }
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] == 1) {
                return i + 1;
            }
        }
        return 0;
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    Solution s;
    cout << s.findTheWinner(5, 2) << endl;
    cout << s.findTheWinner(6, 5) << endl;
    return 0;
}
