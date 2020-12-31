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
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<PII> data;
        int len = (int)values.size();
        for (int i = 0; i < len; i++) {
            data.PB(MP(values[i], labels[i]));
        }
        sort(data.begin(), data.end());
        map<int, int> H;
        int res = 0;
        int cnt = 0;
        for (int i = len - 1; i >= 0; i--) {
            int value = data[i].first;
            int label = data[i].second;
            if (H.find(label) == H.end()) {
                H[label] = 0;
            }
            if(H[label] >= use_limit) {
                continue;
            } else {
                H[label]++;
                cnt++;
                res += value;
            }
            if (cnt >= num_wanted) break;
        }
        return res;
    }
};

int main() {
    return 0;
}

