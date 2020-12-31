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
    set<string> res;
    int len;
    void dfs(string s, int a, int b) {
        if (res.find(s) != res.end()) return;
        else {
            res.insert(s);
            string incS = s;
            
            for (int i = 1; i < len; i+=2) {
                incS[i] = ((s[i] - '0' + b) % 10) + '0';
            }

            dfs(incS, a, b);

            string shiftS = "";
            for (int i = 0; i < len; i++) {
                shiftS += s[(i + b) % len];
            }
            dfs(shiftS, a, b);
        }
    }
    string findLexSmallestString(string s, int a, int b) {
        this->len = (int)s.length();
        dfs(s, a, b);
        return (*res.begin());
    }
};

int main()
{
    return 0;
}

