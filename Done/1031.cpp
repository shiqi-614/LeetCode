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
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> rangeSum;
        int sum = 0;
        int len = (int)A.size();
        for (int i = 0; i < len; i++) {
            sum += A[i];
            if (i >= M) {
                sum -= A[i - M];
            }
            if (i >= M - 1) {
                rangeSum.push_back(sum);
            }
        }
//        cout<<"rangeSum:"<<endl; for (int i = 0; i < (int)rangeSum.size(); i++) {cout<<rangeSum[i]<<" ";} cout<<endl;
        vector<int> leftMax((int)rangeSum.size(), 0);
        vector<int> rightMax((int)rangeSum.size(), 0);
        for (int i = 0; i < (int)rangeSum.size(); i++) {
            if (i - 1 >= 0) {
                leftMax[i] = max(leftMax[i - 1], rangeSum[i]);
            } else {
                leftMax[i] = rangeSum[i];
            }
        }

//        cout<<"leftMax:"<<endl; for (int i = 0; i < (int)leftMax.size(); i++) {cout<<leftMax[i]<<" ";} cout<<endl;
        for (int i = (int)rangeSum.size() - 1; i >= 0; i--) {
            if (i + 1 <= (int)rangeSum.size() - 1) {
                rightMax[i] = max(rightMax[i + 1], rangeSum[i]);
            } else {
                rightMax[i] = rangeSum[i];
            }
        }

        //cout<<"rightMax:"<<endl; for (int i = 0; i < (int)rightMax.size(); i++) {cout<<rightMax[i]<<" ";} cout<<endl;
        int res = -(1<<30);
        sum = 0;
        for (int i = 0; i < len; i++) {
            sum += A[i];
            if (i >= L) {
                sum -= A[i - L];
            }
            if (i >= L - 1) {
                int tmp = -(1<<30);
                if (i - L - M + 1 >= 0) tmp = max(tmp, leftMax[i - L - M + 1]);
                if (i + 1 < (int)rangeSum.size()) tmp = max(tmp, rightMax[i + 1]);
                if (sum + tmp > res) {
                }
                res = max(res, sum + tmp);
            }
        }
        return res;
    }
};

int main() {
    vector<int> data;
    data.PB(3);data.PB(8);data.PB(1);data.PB(3);data.PB(2);data.PB(1);data.PB(8);data.PB(9);data.PB(0);
    Solution s;
    cout<<s.maxSumTwoNoOverlap(data, 3, 2)<<endl;
    return 0;
}

