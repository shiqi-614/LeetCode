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
    int getPrefixCnt(int prefix, LL n) {
        LL cur = prefix;
        LL nxt = prefix + 1;
        LL res = 0;
        while(cur <= n) {
            res += (min(n + 1, nxt) - cur);
            nxt *= 10;
            cur *= 10;
        }
        return res;
    }

    int findKthNumber(int n, int k) {
        int prefix = 1;
        int index = 1;
        while(index < k) {
            int cnt = getPrefixCnt(prefix, n);
            if (index + cnt <= k) {
                prefix++;
                index += cnt;
            } else {
                prefix *= 10;
                index++;
            }  
        }
        return prefix;
    }
};

int main() {
    Solution s;

    for (int i = 1; i <= 100; i++) {
        cout<<s.findKthNumber(100, i)<<endl;
    }
    return 0;
}

