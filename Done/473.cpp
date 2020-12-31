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
    int len;
    set<int> states;
    vector<int> nums;
    map<int, bool> H;
    void dfs(int state, int sum) {
        if (sum == 0) {
            states.insert(((1<<len) - 1) ^ state);
        } else {
            for (int i = 0; i < len; i++) if ((1<<i) & state) {
                if (nums[i] <= sum) {
                    dfs((1<<i) ^ state, sum - nums[i]);
                }
            }
        }
    }

    bool check(int state) {
        if (state == 0) {
            return true;
        } else {
            if (H.find(state) != H.end()) {
                return H[state];
            }
            H[state] = false;
            int sz = (int)states.size();
            set<int>::iterator it;
            for (it = states.begin(); it != states.end(); it++) if ((state & *it) == *it) {
                H[state] |= check(state ^ *it);
            }
            return H[state];
        }
    }
    bool makesquare(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->len = (int)nums.size();
        this->nums = nums;
        this->H.clear();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 4 != 0 || sum == 0) {
            return false;
        }
        
        //cout<<"len:"<<sum / 4<<endl;

        dfs((1<<len) - 1, sum/4);
        //cout<<"state size:"<<states.size()<<endl;
        //for (int i = 0; i < len; i++) cout<<nums[i]<<" "; cout<<endl;
        return check((1<<len) - 1);
    }

};

int main() {
    Solution s;
    int a[] = {7,1,13,6,19,18,12,3,15,4,20,11,2,15,14};
    vector<int> data(a, a + sizeof(a) / sizeof(int));
    cout<<s.makesquare(data)<<endl;

    return 0;
}

