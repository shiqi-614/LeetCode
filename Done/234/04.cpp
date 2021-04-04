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

const int MOD = 1e9 + 7;
class Solution {
public:
    LL getRes(LL primeFactors)
    {
        LL base = 3;
        LL res = 1;
        while (primeFactors) {
            if (primeFactors & 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            primeFactors /= 2;
        }
        return res;
    }
    int maxNiceDivisors(int primeFactors)
    {
        if (primeFactors <= 3) {
            return primeFactors - 1;
        } else {
            if (primeFactors % 3 == 1) {
                return (2 * 2 * getRes((primeFactors - 4) / 3)) % MOD;
            } else if (primeFactors % 3 == 2) {
                return (2 * getRes((primeFactors - 2) / 3)) % MOD;
            } else {
                return getRes(primeFactors / 3);
            }
        }
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    Solution s;
    cout << s.maxNiceDivisors(5) << endl;
    cout << s.maxNiceDivisors(8) << endl;
    return 0;
}
