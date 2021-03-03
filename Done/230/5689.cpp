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
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue)
    {
        int len = (int)items.size();
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (ruleKey == "type" && ruleValue == items[i][0]) {
                cnt++;
            } else if (ruleKey == "color" && ruleValue == items[i][1]) {
                cnt++;
            } else if (ruleKey == "name" && ruleValue == items[i][2]) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    return 0;
}
