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
    string s;
    int dfs(int st, int ed) {
        //cout<<st<<" ed:"<<ed<<endl;
        if (st == ed) return 0;
        else {
            int res = 0;
            int idx = st;
            int sum = 0;
            while(idx <= ed) {
                if (s[idx] == '(') {
                    if (sum == 0) {
                        st = idx;
                    }
                    sum++;
                } else if (s[idx] == ')') {
                    sum--;
                    if (sum == 0) {
                        res = max(res, dfs(st + 1, idx - 1) + 1);
                    }
                }
                idx++;
            }
            return res;
        }
    }
    int maxDepth(string s) {
        this->s = s;
        int len = (int)s.length();
        if (len == 0) return 0;
        return dfs(0, len - 1);
    }
};
int main()
{
    Solution s;
    cout<<s.maxDepth("(1+(2*3)+((8)/4))+1")<<endl;
    cout<<s.maxDepth("(1)+((2))+(((3)))")<<endl;
    cout<<s.maxDepth("1+(2*3)/(2-1)")<<endl;
    cout<<s.maxDepth("1")<<endl;
    return 0;
}

