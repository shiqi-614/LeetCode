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
    string licenseKeyFormatting(string S, int K)
    {
        int len = (int)S.length();
        int cnt = K;
        string res = "";
        for (int i = len - 1; i >= 0; i--) {
            if (S[i] == '-')
                continue;
            cnt--;
            res += S[i];
            if (cnt == 0) {
                res += '-';
                cnt = K;
            }
        }

        reverse(res.begin(), res.end());
        if (res.length() > 0 && res[0] == '-')
            return res.substr(1);
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.licenseKeyFormatting("5F3Z-2e-9-w", 4) << endl;
    cout << s.licenseKeyFormatting("2-5g-3-J", 2) << endl;
    return 0;
}
