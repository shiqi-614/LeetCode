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
    int reverse(int num)
    {
        int res = 0;
        while (num) {
            int tmp = num % 10;
            num = num / 10;
            res = res * 10 + tmp;
        }
        return res;
    }
    bool isSameAfterReversals(int num)
    {
        int tmp1 = reverse(num);
        int tmp2 = reverse(tmp1);
        return tmp2 == num;
    }
};

int main()
{
    return 0;
}
