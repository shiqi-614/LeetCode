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
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = (int)nums.size();
        LL sum = 0;
        for (int i = len - 2; i >= 0; i--) {
            nums[i] += sum;
//            cout<<"i + 1:"<<nums[i + 1]<<" "<<nums[i]<<endl;
            LL x = (nums[i + 1] - nums[i]) * 1LL * (len - 1 - i);
            sum += x;
            nums[i] += x;
//            nums[i + 1] += ((len - 1 - i - 1) * x) / (len - 1 - i);
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> data;
    //data.push_back(1);
    //data.push_back(2);
    //data.push_back(3);
    //data.push_back(8);
    //data.push_back(10);
    //data.push_back(10);
    //data.push_back(10);
    data.push_back(1);
    data.push_back(3);
    data.push_back(6);
    data.push_back(7);
    cout<<s.minMoves(data)<<endl;
    return 0;
}

