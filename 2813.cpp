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

typedef long long LL;
typedef pair<int, int> PII;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k)
    {
        sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
            return a[0] > b[0];
        });
        vector<int> duplicate;
        int len = (int)items.size();
        LL sum = 0;
        LL res = 0;
        set<int> vis;
        for (int i = 0; i < len; i++) {
            int profit = items[i][0], category = items[i][1];
            if (i < k) {
                sum += profit;
                if (vis.find(category) == vis.end()) {
                    vis.insert(category);
                } else {
                    duplicate.push_back(profit);
                }
            } else {
                if (vis.find(category) == vis.end() && duplicate.size() > 0) {
                    sum -= duplicate.back();
                    duplicate.pop_back();
                    sum += profit;
                    vis.insert(category);
                }
            }
            res = max(res, sum + (LL)vis.size() * (LL)vis.size());
        }
        return res;
    }
};

int main()
{
    return 0;
}
