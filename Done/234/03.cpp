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
    map<string, string> H;
    string evaluate(string s, vector<vector<string>>& knowledge)
    {
        int len = (int)knowledge.size();
        for (int i = 0; i < len; i++) {
            H[knowledge[i][0]] = knowledge[i][1];
        }
        len = (int)s.length();
        string res = "";
        string cur = "";
        bool isInBracket = 0;
        for (int i = 0; i < len; i++) {
            if (isInBracket) {
                if (s[i] != ')') {
                    cur += s[i];
                } else {
                    isInBracket = 0;
                    if (H.find(cur) == H.end()) {
                        res += "?";
                    } else {
                        res += H[cur];
                    }
                    cur = "";
                }
            } else if (s[i] == '(') {
                isInBracket = 1;
            } else {
                res += s[i];
            }
        }

        return res;
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    return 0;
}
