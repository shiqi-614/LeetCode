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

typedef long long LL;
typedef pair<int, int> PII;

class Solution {
public:
    int getMaxRht(vector<vector<int>>& fruits, int startPos, int k)
    {
        int len = (int)fruits.size();
        int lft = -1;
        int rht = -1;
        int sum = 0;
        int mx = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (fruits[i][0] - k <= startPos) {
                lft = i;
                rht = i;
                break;
            }
        }
        if (lft == -1 || rht == -1)
            return 0;
        while (rht >= 0 && fruits[rht][0] >= startPos) {
            int remain = (startPos - (fruits[rht][0] - k));
            while (lft >= 0) {
                int tmp = startPos - fruits[lft][0];
                if (tmp * 2 <= remain) {
                    sum += fruits[lft--][1];
                } else {
                    break;
                }
            }
            mx = max(mx, sum);
            // cout << "lft:" << lft << " rht:" << rht << " sum:"<<sum<<endl;
            sum -= fruits[rht--][1];
        }
        // cout << "rht mx:" << mx << endl;
        return mx;
    }
    int getMaxLft(vector<vector<int>>& fruits, int startPos, int k)
    {
        int lft = -1;
        int rht = -1;
        int sum = 0;
        int mx = 0;
        int len = (int)fruits.size();
        for (int i = 0; i < len; i++) {
            if (fruits[i][0] + k >= startPos) {
                lft = i;
                rht = i;
                break;
            }
        }
        if (lft == -1 || rht == -1)
            return 0;
        while (lft < len && fruits[lft][0] <= startPos) {
            int remain = (fruits[lft][0] + k - startPos);
            while (rht < len) {
                int tmp = fruits[rht][0] - startPos;
                if (tmp * 2 <= remain) {
                    sum += fruits[rht++][1];
                } else {
                    break;
                }
            }
            mx = max(mx, sum);
            // cout << "lft:" << lft << " rht:" << rht << " sum:"<<sum<< endl;
            sum -= fruits[lft++][1];
            // cout<<"new sum:"<<sum<<endl;
        }
        // cout << "lft mx:" << mx << endl;
        return mx;
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k)
    {
        return max(getMaxLft(fruits, startPos, k), getMaxRht(fruits, startPos, k));
    }
};
int main()
{
    return 0;
}
