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
    vector<long long> getDistances(vector<int>& arr)
    {
        map<int, int> H;
        vector<vector<int>> order;
        int idx = 0;
        int len = (int)arr.size();
        for (int i = 0; i < len; i++) {
            if (H.find(arr[i]) == H.end()) {
                H[arr[i]] = idx++;
                order.push_back(vector<int>());
            } else {
                order[H[arr[i]]].push_back(i);
            }
        }
        vector<vector<LL>> preSum(idx);
        for (int i = 0; i < idx; i++) {
            LL sum = 0;
            for (int j = 0; j < order[i].size(); j++) {
                sum += order[i][j];
                preSum[i].push_back(sum);
            }
        }
        vector<LL> res(len);
        for (int i = 0; i < idx; i++) {
            len = (int)order[i].size();
            LL sum = preSum[i][len - 1];
            for (int j = 0; j < len; j++) {
                LL pos = order[i][j];
                LL tmp1 = 0;
                if (j - 1 >= 0) {
                    tmp1 = (pos * j) - preSum[i][j - 1];
                }
                LL tmp2 = (sum - preSum[i][j]) - (len - 1 - j) * pos;
                cout << "sum:" << sum << " preSum:" << preSum[i][j] << " pos:" << pos << endl;
                res[pos] = (tmp1 + tmp2);
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
