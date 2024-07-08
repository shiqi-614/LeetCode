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

typedef long long LL;
typedef pair<int, int> PII;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        int len = (int)s.length();
        queue<int> que;
        int mx = 0;
        int lft = 0;
        for (int i = 0; i < len; i++) {
            if (i - 1 >= 0 && s[i] == s[i - 1]) {
                que.push(i - 1);
            }
            if (que.size() <= 1) {
                mx = max(mx, i - lft + 1);
            } else {
                lft = que.front() + 1;
                que.pop();
            }
            //          cout<<"i:"<<i<<" lft:"<<lft<<endl;

            mx = max(mx, i - lft + 1);
        }
        return mx;
    }
};
int main()
{
    return 0;
}
