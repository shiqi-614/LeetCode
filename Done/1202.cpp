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
const int N = 100005;
class Solution {
public:
    int fa[N];
    int find_fa(int x) {
        if (fa[x] != x) {
            fa[x] = find_fa(fa[x]);
        }
        return fa[x];
    }
    void unin(int a, int b) {
        int x = find_fa(a);
        int y = find_fa(b);
        if (x != y) fa[x] = y;
    }
    string smallestStringWithSwaps(string s, vector<vector<int> >& pairs) {
        int len = (int)s.length();
        for (int i = 0; i < len; i++) fa[i] = i;
        for (int i = 0; i < (int)pairs.size(); i++) {
            int x = pairs[i][0];
            int y = pairs[i][1];
            unin(x, y);
        }
        map<int, vector<char> > H;
        for (int i = 0; i < len; i++) {
            int idx = find_fa(i);
            if (H.find(idx) == H.end()) {
                H.insert(MP(idx, vector<char>()));
            }
            H[idx].PB(s[i]);
        }

        for (map<int, vector<char> >::iterator it = H.begin(); it != H.end(); it++) {
            sort(it->second.begin(), it->second.end());
        }

        map<int, int> index;
        string res = "";
        for (int i = 0; i < len; i++) {
            int fa = find_fa(i);
            if (index.find(fa) == index.end()) {
                index.insert(MP(fa, 0));
            }
            res += H[fa][index[fa]++];
        }
        return res;

    }
};

int main() {
    return 0;
}

