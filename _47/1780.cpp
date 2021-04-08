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

const int LIMIT = 1e7 + 5;
class Solution {
public:
    bool checkPowersOfThree(int n)
    {
        vector<int> data;
        LL base = 1;
        while (base < LIMIT) {
            data.push_back(base);
            base = base * 3;
        }

        int idx = (int)data.size() - 1;
        while (n && idx >= 0) {
            if (n >= data[idx]) {
                n -= data[idx];
            }
            idx--;
        }
        return n == 0;
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    return 0;
}
