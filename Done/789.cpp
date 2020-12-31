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
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis = target[0] + target[1];
        for (int i = 0; i < (int)ghosts.size(); i++) {
            int x = ghosts[i][0];
            int y = ghosts[i][1];
            int tmp = abs(x - target[0]) + abs(y - target[i]);
            if (tmp < dis) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}

