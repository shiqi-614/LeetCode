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
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int len = (int)heights.size();
        int sum1 = 0;
        int sum2 = 0;
        priority_queue<int, std::vector<int>, greater<int>> que;
        int res = 0;
        for (int i = 0; i < len - 1; i++) {
            if (heights[i + 1] <= heights[i]) continue;
            else {
                int tmp = heights[i + 1] - heights[i];
                sum1 += tmp;
                if (que.size() < ladders) {
                    que.push(tmp);
                    sum2+= tmp;
                } else {
                    if (que.top() < tmp) {
                        sum2 -= que.top();
                        que.pop();
                        sum2 += tmp;
                    }
                }
                if (sum1 - sum2 <= bricks) {
                    res = i;
                } else {
                    break;
                }
            } 
        }
        return res;
    }
};

int main()
{
    return 0;
}

