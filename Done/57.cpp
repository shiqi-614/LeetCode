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
    vector<int> getRes(int begin, int cnt) {
        vector<int> res;
        for (int i = begin; i < begin + cnt; i++) {
            res.push_back(i);
        }
        return res;
    }
    vector<vector<int> > findContinuousSequence(int target) {
        vector<vector<int> > res;
        for (int i = target / 2; i >= 2; i--) if ((2 * target) % i == 0) {
            int n = i;
            int tmp = ((2 * target) / n) - n + 1;
            if (tmp % 2 == 0 && tmp > 0) {
                int begin = tmp /2;
                res.push_back(getRes(begin, n));
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

