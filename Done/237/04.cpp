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

const int N = 40;

class Solution {
public:
    vector<LL> getData(vector<int>& arr)
    {
        vector<LL> data(N, 0);
        int len = (int)arr.size();
        for (int i = 0; i < len; i++) {
            int tmp = arr[i];
            int cnt = 0;
            while (tmp) {
                if (tmp % 2) {
                    data[cnt]++;
                }
                tmp /= 2;
                cnt++;
            }
        }
        return data;
    }
    int getXORSum(vector<int>& arr1, vector<int>& arr2)
    {
        vector<LL> data1 = getData(arr1);
        vector<LL> data2 = getData(arr2);
        LL res = 0;
        for (int i = 0; i < N; i++) {
            if (data1[i] * data2[i] % 2) {
                res |= (1 << i);
            }
        }
        return res;
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    return 0;
}
