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
    int tribonacci(int n) {
        vector<int> data(n + 1, 0);
        data[1]=1;
        data[2]=1;
        for (int i = 4; i <= n; i++) {
            data[i] = data[i-1] + data[i-2] + data[i-3];
        }
        return data[n];
    }
};

int main() {
    return 0;
}

