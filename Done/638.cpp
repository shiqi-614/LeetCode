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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
class Solution {
public:
    map<int, int> H;
    int toNum(vector<int>& needs) {
        int len = (int)needs.size();
        int res = 0;
        for (int i = 0; i <len; i++) {
            if (needs[i] < 0) return -1;
            res = res * 10 + needs[i];
        }
        return res;
    }

    int dotMul(vector<int>& price, vector<int>& needs) {
        int res = 0;
        for (int i = 0; i < (int)needs.size(); i++) {
            res += needs[i] * price[i];
        }
        return res;
    }

    int dfs(vector<int>& price, vector<vector<int> >& special, vector<int>& needs) {
        int state = toNum(needs);
        if (state == 0) {
            return 0;
        } else {
            if (H.find(state) != H.end()) return H[state];
            H[state] = dotMul(price, needs);;
            for (int i = 0; i <(int)special.size(); i++) {
                for (int j = 0; j < (int)special[i].size() - 1; j++) {
                    needs[j] = needs[j] - special[i][j];
                }
                int nextState = toNum(needs);
                if (nextState != -1) {
                    H[state] = min(H[state], dfs(price, special, needs) + special[i].back());
                }
                for (int j = 0; j < (int)special[i].size() - 1; j++) {
                    needs[j] = needs[j] + special[i][j];
                }
            }
            
            return H[state];
        }
    }

    int shoppingOffers(vector<int>& price, vector<vector<int> >& special, vector<int>& needs) {
        H.clear();
        if (needs.empty()) return 0;
        return dfs(price, special, needs);
    }
};
int main()
{
    return 0;
}

