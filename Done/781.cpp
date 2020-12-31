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
    int numRabbits(vector<int>& answers) {
        map<int, int> H;
        for (int i = 0; i < (int)answers.size(); i++) {
            H[answers[i]]++;
        }

        int res = 0;
        map<int, int>::iterator it;
        for (it = H.begin(); it != H.end(); it++) {
            int key = it->first;
            int value = it->second;
            res += (value / (key + 1) + (value % (key + 1) != 0)) * (key + 1);
        }
        return res;
    }
};

int main() {
    return 0;
}

