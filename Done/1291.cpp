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
    vector<int> getBegin(int idx, int st, int ed) {
        LL val = idx;
        vector<int> res;
        while(val <= ed && idx <= 9) {
            cout<<"val:"<<val<<endl;
            if (val >= st) {
                res.push_back(val);
            }
            val = val * 10 + (++idx);
        }
        return res;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            vector<int> data = getBegin(i, low, high);
            res.insert(res.end(), data.begin(), data.end());
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    s.sequentialDigits(100, 300);
    return 0;
}

