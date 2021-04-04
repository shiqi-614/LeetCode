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
    string getRes(string s)
    {
        int len = (int)s.length();
        string res = "";
        bool flag = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '0' && res == "") {
                continue;
            } else {
                flag = 1;
                res += s[i];
            }
        }
        if (flag == 0) {
            return "0";
        } else {
            return res;
        }
    }

    int numDifferentIntegers(string word)
    {
        int len = (int)word.length();
        set<string> data;
        string cur;
        bool flag = 0;
        for (int i = 0; i < len; i++) {
            if (word[i] >= '0' && word[i] <= '9') {
                flag = 1;
                cur += (word[i]);
            } else {
                if (flag) {
                    data.insert(getRes(cur));
                    flag = 0;
                    cur = "";
                }
            }
        }
        if (flag) {
            data.insert(getRes(cur));
        }
        return (int)data.size();
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    Solution s;
    cout << s.numDifferentIntegers("a1b01c001") << endl;
    return 0;
}
