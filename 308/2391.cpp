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

const char garbageChr[] = { 'M', 'P', 'G' };

class Solution {
public:
    int getGarbage(string str, char chr)
    {
        int cnt = 0;
        int len = (int)str.length();
        for (int i = 0; i < len; i++) {
            if (str[i] == chr) {
                cnt++;
            }
        }
        return cnt;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel)
    {
        int len = (int)garbage.size();
        vector<int> sum(3, 0);
        for (int i = len - 1; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                int cnt = getGarbage(garbage[i], garbageChr[j]);
                if (cnt > 0) {
                    sum[j] += cnt;
                }
                if (i > 0 && (sum[j] > 0 || cnt > 0)) {
                    sum[j] += travel[i - 1];
                }
            }
        }
        return sum[0] + sum[1] + sum[2];
    }
};

int main()
{
    return 0;
}
