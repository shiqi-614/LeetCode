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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int len = (int)s.length();
        vector<int> first(30, 0);
        vector<int> res(30, 0);
        for (int i = 0; i < len; i++) {
            int tmp = s[i] - 'a';
            if (first[tmp] == 0) {
                first[tmp] = i;
            } else {
                res[tmp] = i - first[tmp];
            }
        }

        for (int i = 0; i < 30; i++) {
            if (res[i] != 0) {
                if (res[i] != distance[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}


