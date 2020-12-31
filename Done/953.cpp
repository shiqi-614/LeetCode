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
    map<char, int> H;
    bool cmp(string &x, string &y) {
        int len = min((int)x.length(), (int)y.length());
        for (int i = 0; i < len; i++) {
            if (H[x[i]] == H[y[i]]) continue;
            else if (H[x[i]] > H[y[i]]) {
                return false;
            } else {
                return true;
            }
        }
        return (int)x.length() <= (int)y.length();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        H.clear();
        int len = (int)order.size();
        for (int i = 0; i < len; i++) {
            H[order[i]] = i;
        }
        for (int i = 0; i < (int)words.size() - 1; i++) {
            if (cmp(words[i], words[i + 1]) == false) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}

