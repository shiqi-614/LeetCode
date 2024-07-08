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
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int sum = 0;
        int numEmpty = 0;
        while (numBottles > 0 || numEmpty >= numExchange) {
            if (numEmpty >= numExchange) {
                numEmpty -= numExchange;
                numExchange++;
                numBottles++;
            }
            numEmpty += numBottles;
            sum += numBottles;
            numBottles = 0;
        }
        return sum;
    }
};

int main()
{
    return 0;
}
