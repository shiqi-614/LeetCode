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

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int len = (int)satisfaction.size();
        vector<int> preSum(len, 0);
        int sum = 0;
        for (int i = len - 1; i >= 0; i--) {
            sum += satisfaction[i];
            preSum[i] = sum;
        }

        int res = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (preSum[i] > 0) {
                res += preSum[i];
            } else {
                break;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}

