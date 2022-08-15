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

const int N = 1e5 + 5;

class Solution {
public:
    bool vis[N];
    bool validPartition(vector<int>& nums) {
        memset(vis, 0, sizeof(vis));
        vis[0] = 1;
        int len = (int)nums.size(); 
        for (int i = 0; i < len; i++) if (vis[i]) {
            if (i + 1 < len && nums[i] == nums[i + 1]) {
                vis[i + 2] = 1;
            }

            if (i + 2 < len && nums[i] == nums[i + 1] && nums[i] == nums[i + 2]) {
                vis[i + 3] = 1;
            }

            if (i + 2 < len && nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2]) {
                vis[i + 3] = 1;
            }
        }
        return vis[len];
    }
};

int main()
{
    return 0;
}


