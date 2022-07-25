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
    int fillCups(vector<int>& amount) {
        int res = 0;
        sort(amount.begin(), amount.end());
        while(amount[2] > 0) {
            if (amount[2] > 0&& amount[1] > 0) {
                amount[2]--;
                amount[1]--;
            } else {
                amount[2]--;
            }
            sort(amount.begin(), amount.end());
            res++;
        }
        return res;
    }
};

int main()
{
    return 0;
}


