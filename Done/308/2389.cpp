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
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries)
    {
        sort(nums.begin(), nums.end());
        int len = (int)queries.size();
        int n = (int)nums.size();
        vector<int> res;
        for (int i = 0; i < len; i++) {
            int sum = 0;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (sum + nums[j] <= queries[i]) {
                    sum += nums[j];
                    cnt++;
                } else {
                    res.push_back(cnt);
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
