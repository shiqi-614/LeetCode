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
    int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        }
        int len = num / k + (num % k > 0);
        for (int i = 1; i <= len; i++) {
            int tmp = num - k * i;
            if (tmp % 10 == 0) {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}


