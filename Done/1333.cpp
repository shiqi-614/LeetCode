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
    vector<int> filterRestaurants(vector<vector<int> >& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int n = (int)restaurants.size();
        vector<PII>  res;
        for (int i = 0; i < n; i++) {
            if ((restaurants[i][2] == veganFriendly || veganFriendly == 0) && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
                res.PB(MP(restaurants[i][1], restaurants[i][0]));
            }
        }

        sort(res.begin(), res.end(), greater<PII>());
        vector<int> output;
        for (int i = 0; i < (int)res.size(); i++) {
            output.PB(res[i].second);
        }
        return output;
    }
};

int main() {
    return 0;
}

