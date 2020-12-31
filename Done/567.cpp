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
    bool check(vector<int> cnt1, vector<int> cnt2) {
        for (int i = 0; i < 30; i++) {
            if (cnt1[i] != cnt2[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int len = (int)s1.length();
        vector<int> requirement(30, 0);
        for (int i = 0; i < len; i++) {
            requirement[s1[i]-'a']++;
        }

        vector<int> cnt(30, 0);
        for (int i = 0; i < (int)s2.length(); i++) {
            if (i >= len) {
                cnt[s2[i - len] - 'a']--;
            }
            cnt[s2[i] - 'a']++;
            if (check(cnt, requirement)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}

