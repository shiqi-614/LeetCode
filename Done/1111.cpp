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
    vector<int> maxDepthAfterSplit(string seq) {
        int len = (int)seq.length();
        vector<int> res;
        int dep1 = 0;
        int dep2 = 0;
        for (int i = 0; i < len; i++) {
            if (seq[i] == '(') {
                if (dep1 > dep2) {
                    res.push_back(1);
                    dep2 += 1;
                } else {
                    res.push_back(0);
                    dep1 += 1;
                }
            } else {
                if (dep1 > dep2) {
                    dep1--;
                    res.push_back(0);
                } else {
                    dep2--;
                    res.push_back(1);
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

