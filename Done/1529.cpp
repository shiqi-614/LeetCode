#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

class Solution {
public:
    int minFlips(string target) {
        int len = (int)target.length();
        int sum = 0;
        for (int i = 0;i < len; i++) {
            if (sum % 2 != target[i] - '0') {
                sum++;
            }
        }
        return sum;
    }
};
int main()
{
    return 0;
}

