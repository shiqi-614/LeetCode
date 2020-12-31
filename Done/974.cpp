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
    int subarraysDivByK(vector<int>& A, int K) {

        int len = (int)A.size();
        map<int, int> H;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += A[i];
            sum %= K;
            if (sum < 0) {
                sum += K;
            }
            H[sum]++;
        }
        map<int, int>::iterator it;
        int res = 0;
        for (it = H.begin(); it != H.end(); it++) {
            int cnt = it -> second;
            res += (cnt * (cnt - 1)) / 2;
            cout<<it->first<<" cnt:"<<it->second<<endl;
            if (it->first == 0) {
                res += cnt;
            }
        }
        return res;
    }
};

int main() {
    int a[] = {4,5,0,-2,-3,1};
    vector<int> data(a, a + sizeof(a) / sizeof(int));
    Solution s;
    cout<<s.subarraysDivByK(data, 5)<<endl;
    return 0;
}

