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
    bool canConstruct(string s, int k) {
        int len = (int)s.length();
        int cnt[30] = {0};
        for (int i = 0; i < len; i++) {
            cnt[s[i]-'a']++;
        }
        int odd = 0;
        int even = 0;
        for (int i = 0; i < 30; i++) {
            if (cnt[i] % 2) {
                odd++;
                cnt[i]--;
            } 
            even += cnt[i] / 2;
        }
        cout<<odd<<" "<<even<<endl;
        if (odd > k) return false;

        if (odd + even >= k) return true;
        if (odd + even < k) {
            if (odd + even * 2 >= k) return true;
        }

        return false;
    }
};

int main() {
    Solution s;
//    cout<<s.canConstruct("qlkzenwmmnpkopu", 15)<<endl;
    cout<<s.canConstruct("ibzkwaxxaggkiwjbeysz", 15)<<endl;
    return 0;
}

