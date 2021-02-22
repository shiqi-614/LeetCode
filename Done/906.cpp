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

const int LIMIT = 1e5;
class Solution {
public:
    LL lft;
    LL rht;
    LL limit;
    LL toNum(string num)
    {
        LL res = 0;
        for (int i = 0; i < (int)num.length(); i++) {
            res = res * 10 + (num[i] - '0');
        }
        return res;
    }

    string toString(LL tmp)
    {
        string res = "";
        while (tmp) {
            res += ((tmp % 10) + '0');
            tmp /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool checkParam(LL tmp)
    {
        string res = toString(tmp);
        string rev = res;
        reverse(rev.begin(), rev.end());
        return rev == res;
    }
    LL getParam1(LL cur)
    {
        string res = toString(cur);
        string rev = res;
        reverse(rev.begin(), rev.end());
        string output = res + rev;
        return toNum(output);
    }
    LL getParam2(LL cur)
    {
        string res = toString(cur);
        string rev = res;
        reverse(rev.begin(), rev.end());
        string output = res + rev.substr(1);
        return toNum(output);
    }
    bool check(LL param)
    {
        if (param <= limit) {
            LL tmp = param * param;
            if (tmp >= lft && tmp <= rht && checkParam(tmp)) {
                //cout << "final:" << tmp << endl;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    int superpalindromesInRange(string left, string right)
    {
        lft = toNum(left);
        rht = toNum(right);
        limit = sqrt(rht);

        int res = 0;
        for (int i = 1; i <= LIMIT; i++) {
            LL param1 = getParam1(i);
            if (check(param1)) {
                //cout << "param1:" << param << " -> " << i << endl;
                res++;
            }
            LL param2 = getParam2(i);
            if (check(param2)) {
                //cout << "param2:" << param << " -> " << i << endl;
                res++;
            }
            if (param1 > limit && param2 > limit)
                break;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.superpalindromesInRange("40000000000000000",
        "50000000000000000")
         << endl;
}
