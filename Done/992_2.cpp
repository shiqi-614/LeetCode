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

const int N = 20004;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K)
    {
        int len = (int)A.size();
        int lft1 = 0;
        int lft2 = 0;
        int rht = 0;
        vector<int> cnt1(N, 0);
        vector<int> cnt2(N, 0);
        int tot1 = 0;
        int tot2 = 0;
        int res = 0;
        while (rht < len) {
            if (cnt1[A[rht]] == 0) {
                tot1++;
            }
            cnt1[A[rht]]++;

            if (cnt2[A[rht]] == 0) {
                tot2++;
            }
            cnt2[A[rht]]++;

            //cout << "tot1:" << tot1 << " tot2:" << tot2 << endl;
            while (tot1 > K && lft1 < len) {
                if (cnt1[A[lft1]] == 1) {
                    tot1--;
                }
                cnt1[A[lft1]]--;
                lft1++;
            }
            while (tot2 >= K && lft2 < len) {
                if (cnt2[A[lft2]] == 1) {
                    tot2--;
                }
                cnt2[A[lft2]]--;
                lft2++;
            }
            //cout << "middle:" << lft2 - lft1 << " lft1:" << lft1 << " lft2:" << lft2 << " rht:" << rht << endl;
            res += (lft2 - lft1);
            rht++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> data;

    data.push_back(1);
    data.push_back(2);
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);

    cout << s.subarraysWithKDistinct(data, 2) << endl;

    data.clear();
    data.push_back(1);
    data.push_back(2);
    data.push_back(1);
    data.push_back(3);
    data.push_back(4);

    cout << s.subarraysWithKDistinct(data, 3) << endl;

    int tmp[] = { 1, 2 };
    data.clear();
    int len = sizeof(tmp) / sizeof(int);
    for (int i = 0; i < len; i++)
        data.push_back(tmp[i]);

    cout << s.subarraysWithKDistinct(data, 1) << endl;

    return 0;
}
