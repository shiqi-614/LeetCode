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
    int firstMissingPositive(vector<int>& nums) {
        int len = (int)nums.size();
        int mi = len + 1;
        for (int i = 0; i < len; i++) {
            if (nums[i] <= 0) {
                nums[i] = -1;
            } else {
                mi = min(mi, nums[i]);
            }
        }
        if (mi > 1) return 1;

        for (int i = 0; i < len; i++) {
            int tmp = nums[i];
            if (tmp == i + 1) continue;
            if (tmp > len || tmp <= 0)  nums[i] = -1;
            else {
                while (i + 1 != tmp && tmp != -1) {
                    if (nums[tmp - 1] != tmp) {
                        swap(nums[i], nums[tmp - 1]);
                        tmp = nums[i];
                    } else {
                        nums[i] = -1; 
                        break;
                    }
                }
            }
        }
        //for (int i = 0; i < len; i++) {
            //cout<<nums[i]<<" ";
        //}cout<<endl;

        for (int i = 0; i < len; i++) {
            if (nums[i] == -1) return i + 1;
        }
        return len + 1;
    }
};

int main()
{
    vector<int> data;
    data.push_back(2);
    data.push_back(1);
    Solution s;
    cout<<s.firstMissingPositive(data)<<endl;
    return 0;
}

