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

typedef pair<int, int> PII;
typedef long long LL;

class Solution {
    public:
        LL getRes(int st, int ed, vector<int>& miIdx, vector<int>& mxIdx) {
            if (st != -1 && ed != -1) {
                // cout<<"st:"<<st<<" ed:"<<ed<<endl;
                int idx1 = 0;
                int idx2 = 0;
                int len1 = (int)miIdx.size();
                int len2 = (int)mxIdx.size();
                LL res = 0;
                while(idx1 < len1 && idx2 < len2) {
                    int mi = st;
                    int mx = st;
                    if (idx1 < len1) {
                        mi = min(mi, miIdx[idx1]);
                        mx = max(mx, miIdx[idx1]);
                    }
                    if (idx2 < len2) {
                        mi = min(mi, mxIdx[idx2]);
                        mx = max(mx, mxIdx[idx2]);
                    }

                    res += 1LL * (mi - st + 1) * (ed - mx + 1);
                    st = mi + 1;
                    // cout<<"Idx1:"<<idx1<<" idx2:"<<idx2<<endl;
                    // cout<<"mi:"<<mi<<" mx:"<<mx<<endl;
                    if (mi == miIdx[idx1]) idx1++;
                    if (mi == mxIdx[idx2]) idx2++;
                }
                return res;
            } else {
                return 0;
            }
        }

        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            int len = (int)nums.size();
            int st = -1;
            int ed = -1;
            vector<int> miIdx;
            vector<int> mxIdx;
            LL res = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] < minK || nums[i] > maxK) {
                    res += getRes(st, ed, miIdx, mxIdx);
                    st = -1;
                    ed = -1;
                    miIdx.clear();
                    mxIdx.clear();
                } else {
                    if (st == -1) {
                        st = i;
                    }
                    ed = i;
                    if (nums[i] == minK) {
                        miIdx.push_back(i);
                    }
                    if (nums[i] == maxK){
                        mxIdx.push_back(i);
                    }
                }
                // cout<<"i:"<<i<<" st:"<<st<<" ed:"<<ed<<endl;
            }
            res += getRes(st, ed, miIdx, mxIdx);
            return res;
        }
};

int main()
{
    Solution s;
    // vector<int> data({1,3,5,2,7,5});
    // cout<<s.countSubarrays(data, 1, 5)<<endl;
    vector<int> data({1,1, 1, 1});
    cout<<s.countSubarrays(data, 1, 1)<<endl;
    return 0;
}
