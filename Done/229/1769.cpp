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
    vector<int> minOperations(string boxes)
    {
        int len = (int)boxes.size();
        vector<int> sumPre(len, 0);
        vector<int> sumPos(len, 0);
        vector<int> pre(len, 0);
        vector<int> pos(len, 0);
        for (int i = 0; i < len; i++) {
            if (i > 0) {
                sumPre[i] += sumPre[i - 1];
                pre[i] += pre[i - 1];
                pre[i] += sumPre[i - 1];
            }
            sumPre[i] += (boxes[i] - '0');
        }

        for (int i = len - 1; i >= 0; i--) {
            if (i + 1 < len) {
                sumPos[i] += sumPos[i + 1];
                pos[i] += pos[i + 1];
                pos[i] += sumPos[i + 1];
            }
            sumPos[i] += (boxes[i] - '0');
        }
        vector<int> res(len, 0);
        for (int i = 0; i < len; i++) {
            res[i] = pre[i] + pos[i];
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
