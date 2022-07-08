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
    string decodeMessage(string key, string message) {
        int len = (int)message.length();
        int tot = (int)key.length();
        map<char, char> H;

        int idx = 0;
        int cnt = 0;
        while (idx < tot) {
            if (key[idx] != ' ') {
                if (H.find(key[idx]) == H.end()) {
                    H[key[idx]] = ('a' + cnt);
                    // cout<<key[idx]<<" "<<char('a' + cnt)<<endl;
                    cnt++;
                }
            }
            idx++;

        }
        for (int i = 0; i < tot; i++) {
        }

        string res = "";
        for (int i = 0; i < len; i++) {
            if (message[i] != ' ') {
                res += H[message[i]];
            } else {
                res += ' ';
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.decodeMessage("the quick brown fox jumps over the lazy dog", "vkbs bs t suepuv")<<endl;
    return 0;
}


