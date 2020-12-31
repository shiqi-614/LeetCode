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
    vector<int> replaceElements(vector<int>& arr) {
        int len = (int)arr.size();
        vector<int> mxRight(len, -1);
        for (int i = len - 2; i >= 0; i--) {
            if (mxRight[i + 1] != -1) {
                mxRight[i] = max(mxRight[i + 1], arr[i + 1]);
            } else {
                mxRight[i] = arr[i + 1];
            }
        }
        return mxRight;
    }
};

int main() {
    return 0;
}

