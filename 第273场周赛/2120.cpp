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
    bool check(int n, int& x, int& y, char chr)
    {
        if (chr == 'L') {
            y--;
        } else if (chr == 'R') {
            y++;
        } else if (chr == 'U') {
            x--;
        } else if (chr == 'D') {
            x++;
        }

        if (x >= 0 && x < n && y >= 0 && y < n) {
            return true;
        } else {
            return false;
        }
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s)
    {
        vector<int> res;
        int len = (int)s.length();
        for (int i = 0; i < len; i++) {
            int x = startPos[0];
            int y = startPos[1];
            int output = 0;
            cout << "i:" << i << endl;
            for (int j = i; j < len; j++) {
                if (check(n, x, y, s[j])) {
                    output++;
                } else {
                    break;
                }
                cout << "x:" << x << " y:" << y << endl;
            }
            res.push_back(output);
        }
        return res;
    }
};

int main()
{
    return 0;
}
