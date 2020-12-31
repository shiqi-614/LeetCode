#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int N = 55;
class Solution {
public:
    bool dp[N][1200];

    vector<PII> getStateWithSum(vector<int>& quantity) {
        vector<PII> stateWithSum;
        int len = (int)quantity.size();
        for (int i = 0; i < (1<<len); i++) {
            int sum = 0;
            for (int j = 0; j < len; j++) {
                if (i & (1 << j)) {
                    sum += quantity[j];
                }
            }
            stateWithSum.push_back(make_pair(i, sum));
        }
        return stateWithSum;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int m = (int)quantity.size();
        memset(dp, 0, sizeof(dp));

        map<int,int> H;
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            H[nums[i]]++;
        }

        vector<PII> stateWithSum = getStateWithSum(quantity); 

        map<int, int>::iterator it;
        vector<vector<int> > states;

        for (it = H.begin(); it != H.end(); it++) {
            vector<int> state;
            int cnt = it -> second;
            for (int j = 0; j < (int)stateWithSum.size(); j++) {
                if (stateWithSum[j].second <= cnt) {
                    state.push_back(stateWithSum[j].first);
                }
            }
            states.push_back(state);
        }

        dp[0][0] = 1;
        for (int i = 0; i < (int)states.size(); i++) {
            for (int j = 0; j < (1<<m); j++) if (dp[i][j]) {
                for (int k = 0; k < (int)states[i].size(); k++) {
                    if ((j & states[i][k]) == 0) {
                        int next = j ^ states[i][k];
                        dp[i + 1][next] = 1;
                        if (next == ((1<<m) - 1)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;

    }
};

int main()
{
    return 0;
}

