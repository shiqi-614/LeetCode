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
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k)
    {
        int len = (int)logs.size();
        map<int, set<int>> H;
        int mx = 0;
        vector<int> res(k, 0);
        for (int i = 0; i < len; i++) {
            if (H.find(logs[i][0]) == H.end()) {
                set<int> data;
                data.insert(logs[i][1]);
                H.insert(make_pair(logs[i][0], data));
            } else {
                H[logs[i][0]].insert(logs[i][1]);
            }
        }

        for (auto [key, value] : H) {
            int sz = (int)value.size() - 1;
            res[sz]++;
        }
        return res;
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    return 0;
}
