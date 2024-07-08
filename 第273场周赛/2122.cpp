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
    vector<int> recoverArray(vector<int>& nums)
    {
        int len = (int)nums.size();
        sort(nums.begin(), nums.end());
        vector<int> gapList;
        for (int i = 0; i < len; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        for (int i = 1; i < len; i++) {
            int tmp = nums[i] - nums[0];
            if (tmp % 2 == 0 && tmp > 0) {
                gapList.push_back(nums[i] - nums[0]);
            }
        }
        for (int k = 0; k < (int)gapList.size(); k++) {
            int gap = gapList[k];
            int rht = -1;
            vector<bool> vis(len, 0);
            vector<int> res;
            cout << "gap:" << gap << endl;

            bool find = true;
            for (int i = 0; i < len; i++) {
                if (vis[i] == 1) {
                    continue;
                }
                vis[i] = 1;
                res.push_back(nums[i]);
                if (rht == -1 || rht <= i) {
                    rht = lower_bound(nums.begin(), nums.end(), i + gap) - nums.begin();
                    if (!(rht >= 0 && rht < len)) {
                        find = false;
                        break;
                    }
                }
                bool match = false;
                while (rht < len) {
                    if (vis[rht] == 1) {
                        rht++;
                    } else if (nums[i] + gap != nums[rht]) {
                        break;
                    } else {
                        vis[rht] = 1;
                        rht++;
                        match = true;
                        break;
                    }
                }
                if (match == false) {
                    cout << "match false i" << i << " val:" << nums[i] << " rht:" << rht << endl;
                    find = false;
                }
                if (find == false) {
                    cout << "find false i" << i << " val:" << nums[i] << endl;
                    break;
                }
            }
            if (find) {
                for (int i = 0; i < len / 2; i++) {
                    res[i] += (gap / 2);
                }
                return res;
            }
        }
        return vector<int>();
    }
};

int main()
{
    return 0;
}
