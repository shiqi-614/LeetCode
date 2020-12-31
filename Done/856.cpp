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
    int dfs(string s, int st, int ed) {
        if (st > ed || st + 1 == ed) return 1;
        else {
            int res = 0;
            int cnt = 0;
            int subSt = st;
            for (int i = st; i <= ed; i++) {
                if (s[i] == '(') cnt++;
                else cnt--;
                if (cnt == 0) {
                    if (!(subSt == st && i == ed)) {
                        res += dfs(s, subSt, i);
                        subSt = i + 1;
                    } else {
                        res += 2 * dfs(s, st + 1, ed - 1);
                    }
                }
            }
            return res;
        }
    }
    int scoreOfParentheses(string S) {
        int len = (int)S.length();
        if (len == 0) return 0;
        return dfs(S, 0, (int)S.length() - 1);
    }
};

int main()
{
    Solution s;
    cout<<s.scoreOfParentheses("()")<<endl;
    cout<<s.scoreOfParentheses("(())")<<endl;
    cout<<s.scoreOfParentheses("()()")<<endl;
    cout<<s.scoreOfParentheses("(()(()))")<<endl;
    return 0;
}

