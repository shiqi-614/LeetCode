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

const int N = 1e3 + 5;
int arr[N];
int perm[N];
class Solution {
public:
    int reinitializePermutation(int n)
    {
        for (int i = 0; i < n; i++) {
            perm[i] = i;
        }
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                arr[i] = perm[i / 2];
            } else {
                arr[i] = perm[n / 2 + (i - 1) / 2];
            }
        }

        int mx = 0;
        for (int i = 1; i < n; i++) {
            int root = i;
            int cur = i;
            int cnt = 0;
            while (1) {
                cur = arr[cur];
                if (cur == root) {
                    break;
                }
                cnt++;
            }
            mx = max(mx, cnt);
        }
        return mx + 1;
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    Solution s;
    cout << s.reinitializePermutation(2) << endl;
    cout << s.reinitializePermutation(4) << endl;
    cout << s.reinitializePermutation(6) << endl;
    cout << s.reinitializePermutation(1000) << endl;
    return 0;
}
