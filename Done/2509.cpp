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
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries)
    {
        int len = (int)queries.size();
        vector<int> res;
        for (int i = 0; i < len; i++) {
            int lft = queries[i][0];
            int rht = queries[i][1];

            int cnt = 2;
            while (lft != rht) {
                if (lft > rht)
                    swap(lft, rht);
                rht /= 2;
                cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};

int main()
{
    return 0;
}
