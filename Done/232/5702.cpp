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
    int findCenter(vector<vector<int>>& edges)
    {
        int len = (int)edges.size();
        vector<int> cnt(len + 5, 0);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 2; j++) {
                cnt[edges[i][j]]++;
            }
        }
        for (int i = 1; i <= len + 1; i++) {
            if (cnt[i] == len) {
                return i;
            }
        }
        return 0;
    }
};

int main()
{
    return 0;
}
