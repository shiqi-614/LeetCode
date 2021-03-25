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

const int N = 2500;
int dp[N][N];
int cnt[N][N];

class Solution {
public:
    int minChanges(vector<int>& nums, int K)
    {
        memset(dp, -1, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            cnt[i % K][nums[i]]++;
        }
        // cout << "init" << endl;

        for (int i = 0; i < N; i++) {
            dp[0][i] = cnt[0][i];
        }

        for (int i = 1; i < K; i++) {
            int mx = 0;
            int idx = -1;
            for (int j = 0; j < N; j++) {
                if (mx < dp[i - 1][j]) {
                    mx = dp[i - 1][j];
                    idx = j;
                }
            }

            // cout << "idx:" << idx << endl;
            for (int j = 0; j < N; j++) {
                if (cnt[i][j] == 0) {
                    if ((j ^ idx) < N) {
                        dp[i][j ^ idx] = max(dp[i][j ^ idx], dp[i - 1][idx]);
                    }
                } else {
                    for (int k = 0; k < N; k++) {
                        if (dp[i - 1][k] != -1 && (k ^ j) < N) {
                            dp[i][k ^ j] = max(dp[i][k ^ j], dp[i - 1][k] + cnt[i][j]);
                        }
                    }
                }
            }
        }
        int res = len - dp[K - 1][0];
        return res;
    }
};

int main()
{
    int tmp[] = { 5, 21, 9, 12, 4, 12, 19, 7, 27, 11, 18, 23, 15, 10, 27, 30, 11, 3 };
    // int tmp[] = { 3, 4, 5, 2, 1, 7, 3, 4, 7 };
    // int tmp[] = { 1, 2, 4, 1, 2, 5, 1, 2, 6 };
    // int tmp[] = { 1, 2, 0, 3, 0 };
    int len = sizeof(tmp) / sizeof(int);
    vector<int> data;
    for (int i = 0; i < len; i++) {
        data.push_back(tmp[i]);
    }
    Solution s;
    cout << s.minChanges(data, 8) << endl;

    return 0;
}
