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

const int N = 1e5+5;

class Solution {
public:
    long long sum[N];
    int edgeScore(vector<int>& edges) {
        memset(sum, 0, sizeof(sum));
        int len = (int)edges.size();
        for (int i = 0; i < len; i++) {
            sum[edges[i]] += i;
        }

        long long mx = 0;
        int res = -1;
        for (int i = 0; i < N; i++) {
            if (mx < sum[i]) {
                mx = sum[i];
                res = i;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}


