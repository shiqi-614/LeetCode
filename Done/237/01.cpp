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

const int N = 26;
class Solution {
public:
    bool checkIfPangram(string sentence)
    {
        int len = (int)sentence.length();
        vector<bool> vis(N, 0);
        for (int i = 0; i < len; i++) {
            vis[sentence[i] - 'a'] = 1;
        }
        for (int i = 0; i < N; i++) {
            if (vis[i] == 0) {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    return 0;
}
