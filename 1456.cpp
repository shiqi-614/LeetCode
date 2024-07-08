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

typedef long long LL;
typedef pair<int, int> PII;

class Solution {
public:
    bool isTarget(char chr)
    {
        if (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u') {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k)
    {
        int cnt = 0;
        int res = 0;
        queue<int> que;
        int len = (int)s.length();
        for (int i = 0; i < len; i++) {
            if (que.size() < k) {
                que.push(s[i]);
                if (isTarget(s[i])) {
                    cnt++;
                }
            } else {
                if (isTarget(que.front())) {
                    cnt--;
                }
                que.pop();
                if (isTarget(s[i])) {
                    cnt++;
                }
                que.push(s[i]);
            }
            res = max(res, cnt);
        }
        return res;
    }
};

int main()
{
    return 0;
}
