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
    bool checkOnesSegment(string s)
    {
        int len = (int)s.length();
        int con = 0;
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '1') {
                con++;
            } else {
                if (con > 0) {
                    con = 0;
                    cnt++;
                }
            }
        }
        if (con > 0)
            cnt++;
        //cout << "cnt:" << cnt << endl;
        return cnt == 1;
    }
};

int main()
{
    Solution s;
    cout << s.checkOnesSegment("1000") << endl;
    return 0;
}
