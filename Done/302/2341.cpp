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
    vector<int> numberOfPairs(vector<int>& nums) {
        int cnt = 0;
        int len = (int)nums.size();
        vector<bool> vis(len, false);
        while(1) {
            bool find = false;
            for (int i = 0; i < len; i++) if (vis[i] == false) {
                for (int j = i + 1; j < len; j++) {
                    if (nums[i] == nums[j]) {
                        vis[j] = true;
                        vis[i] = true;
                        find = true;
                        cnt++;
                        break;
                    }
                }
            }
            if (find == false) {
                break;
            }
        }        
        int tmp = 0;
        for (int i = 0; i < len; i++) {
            if (vis[i] == false) {
                tmp++;
            }
        }
        vector<int> res;
        res.push_back(cnt);
        res.push_back(tmp);
        return res;
    }
};

int main()
{
    return 0;
}


