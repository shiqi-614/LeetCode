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

void vectorPrint(vector<int>& data) {
    for (int i = 0; i < (int)data.size(); i++) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
class Solution {
public:
    int res;
    vector<int> dfs(vector<int>& nums, int st, int ed) {
        if (st > ed) {
            return vector<int> ();
        }
        if (st == ed) {
            vector<int> data(1, nums[st]);
            return data;
        } else {

            int mid = (st + ed) / 2;
            vector<int> lft = dfs(nums, st, mid);
            vector<int> rht = dfs(nums, mid + 1, ed);
            //cout<<"left:"<<endl;
            //vectorPrint(lft);
            //cout<<"right:"<<endl;
            //vectorPrint(rht);
            int idx1 = 0;
            int idx2 = 0;
            int len1 = (int)lft.size();
            int len2 = (int)rht.size();
            vector<int> data;
            while(idx1 < len1 || idx2 < len2) {
                if (idx1 < len1 && idx2 < len2) {
                    if (lft[idx1] > rht[idx2]) {
                        data.push_back(lft[idx1]);
                        res += (len2 - idx2);
                        idx1++;
                    } else {
                        data.push_back(rht[idx2]);
                        idx2++;
                    }
                } else if (idx1 < len1) {
                    data.push_back(lft[idx1]);
                    idx1++;
                } else if (idx2 < len2) {
                    data.push_back(rht[idx2]);
                    idx2++;
                }
            }
//            cout<<"merge:"<<endl;
//            vectorPrint(data);
            return data;
        }
    }
    int reversePairs(vector<int>& nums) {
        int len = (int)nums.size();
        res = 0;
        dfs(nums, 0, len - 1);
        return res;
    }
};

int main() {
    int tmp[] = {7,5,6,4};
    vector<int> data(tmp, tmp + sizeof(tmp) / sizeof(int));
    Solution s;
    cout<<s.reversePairs(data)<<endl;
    return 0;
}

