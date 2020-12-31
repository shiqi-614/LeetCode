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
    string toLowerCase(string str) {
        int len = (int)str.length();
        for (int i = 0; i < len; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] += 'a' - 'A';
            }
        }
        return str;
    }
};

int main() {
    return 0;
}

