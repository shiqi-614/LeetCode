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
    vector<int> res;
    void fun(vector<int> &cnt, string s, int num, int chrCnt) {
        for (int i = 0; i < (int)s.length(); i++) {
            cnt[getIdx(s[i])] -= chrCnt;
        }
        for (int i = 0; i < chrCnt; i++) {
            res.push_back(num);
        }
    }
    int getIdx(char chr) {
        return chr - 'a';
    }
    string originalDigits(string s) {
        res.clear();
        vector<int> cnt(30, 0);
        int len = (int)s.length();
        for (int i = 0; i < len; i++) {
            cnt[s[i] - 'a']++;
        }
        fun(cnt, "zero", 0, cnt[getIdx('z')]);
        fun(cnt, "six", 6, cnt[getIdx('x')]);
        fun(cnt, "eight", 8, cnt[getIdx('g')]);
        fun(cnt, "seven", 7, cnt[getIdx('s')]);
        fun(cnt, "five", 5, cnt[getIdx('v')]);
        fun(cnt, "four", 4, cnt[getIdx('f')]);
        fun(cnt, "three", 3, cnt[getIdx('h')]);
        fun(cnt, "two", 2, cnt[getIdx('w')]);
        fun(cnt, "one", 1, cnt[getIdx('o')]);
        fun(cnt, "nine", 9, cnt[getIdx('i')]);
        sort(res.begin(), res.end());
        string output = "";
        for (int i = 0; i < (int)res.size(); i++) {
            output += (res[i] + '0');
        }
        return output;
    }
};

int main()
{
    return 0;
}

