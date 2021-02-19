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

bool check(long long num)
{
    string tmp = "";
    while (num) {
        tmp += (num % 10) + '0';
        num /= 10;
    }
    string rev = tmp;
    reverse(rev.begin(), rev.end());
    return rev == tmp;
}
int main()
{
    long long L = 1;
    long long R = 10000000000;
    int cnt = 0;
    for (long long i = L; i <= R; i++) {
        long long tmp = sqrt(i);
        if (tmp * tmp == i && check(tmp) && check(i)) {
            cnt++;
            cout << tmp << " -> " << i << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}
