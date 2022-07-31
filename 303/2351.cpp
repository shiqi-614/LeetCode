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
    char repeatedCharacter(string s) {
        int len = (int)s.length();
        bool vis[30];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < len; i++) {
            if (vis[s[i] - 'a'] == 1) {
                return s[i];
            }
            vis[s[i] - 'a'] = 1;
        }
        return 'a';
    }
};

int main()
{
    return 0;
}


