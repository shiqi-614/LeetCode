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

typedef long long LL;
typedef pair<int,int> PII;

class Solution {
public:
    bool validate(string s) {
        int lft = 0;
        int rht = (int)s.length() - 1;
        int cnt = 0;
        while(lft < rht) {
            while (s[lft] != s[rht] && lft < rht) {
                rht ++;
                cnt++;
            }
            lft++;
            rht--;
        }
        if (cnt <= 1) {
            return true;
        } else {
            return false;
        }
    }
    bool validPalindrome(string s) {
        bool flag = validate(s);
        reverse(s.begin(), s.end());
        flag |= validate(s);
        return flag;
    }
};


int main() {
    return 0;
}

