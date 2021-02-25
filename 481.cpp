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
    int magicalString(int n)
    {
        string pattern = "122";
        int patternIdx = 2;
        int currentIdx = 2;
        int cnt = 0;
        while (currentIdx < n) {
            if (pattern[patternIdx] == '2') {
                if (pattern[currentIdx] == '1') {
                    pattern += "22";
                } else {
                    pattern += "11";
                }
                currentIdx += 2;
            } else {
                if (pattern[currentIdx] == '1') {
                    pattern += "2";
                } else {
                    pattern += "1";
                }
                currentIdx += 1;
            }
            patternIdx++;
        }
        for (int i = 0; i < n; i++) {
            if (pattern[i] == '1')
                cnt++;
        }
        //cout << "pattern:" << pattern << endl;
        return cnt;
    }
};

int main()
{
    Solution s;
    cout << s.magicalString(6) << endl;
    return 0;
}
