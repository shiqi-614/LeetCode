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
const int MOD = 1e9 + 7;
class Solution {
public:
    int getScore(LL st, LL ed) {
        return ((st * 1LL + ed) * (ed - st + 1) / 2) * 1LL % MOD;
    }
    bool isValid(int val, int orders, vector<int>& inventory) {
        int len = (int)inventory.size();
        LL sum = 0;
        for (int i = 0; i < len; i++) {
            if (inventory[i] >= val) {
               sum += (inventory[i] - val + 1); 
            }
        }
        return sum <= orders;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        int len = (int)inventory.size();
        sort(inventory.begin(), inventory.end());
        int lft = 1;
        int rht = inventory[len - 1];
        while(lft < rht) {
            int mid = (lft + rht) / 2;
            if (isValid(mid, orders, inventory)) {
                rht = mid;
            } else {
                lft = mid + 1;
            }
        }
        priority_queue<int> que;
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (inventory[i] >= lft) {
                que.push(lft - 1);
                res = (res + getScore(lft, inventory[i])) % MOD;
                orders -= (inventory[i] - lft + 1);
            } else {
                que.push(inventory[i]);
            }
        }
        while(orders--) {
            if (!que.empty()) {
                int tmp = que.top(); que.pop();
                res = (res + tmp);
                tmp--;
                que.push(tmp);
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}

