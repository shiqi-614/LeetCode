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
    string truncateSentence(string s, int k)
    {
        int len = (int)s.length();
        int cnt = 0;
        char pre = ' ';
        string res = "";
        for (int i = 0; i < len; i++) {
            if (s[i] != ' ') {
                if (pre == ' ') {
                    cnt++;
                } else {
                }
            } else {
                if (cnt == k) {
                    break;
                }
            }
            pre = s[i];
            res += s[i];
        }
        return res;
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    Solution s;
    cout << s.truncateSentence("Hello how are you Contestant", 4) << endl;
    return 0;
}
