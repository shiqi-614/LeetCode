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
    int maximumGroups(vector<int>& grades) {
        int len = (int)grades.size();
        sort(grades.begin(), grades.end());
        long long sum1 = grades[0];
        long long cnt1 = 1;
        long long sum2 = 0;
        long long cnt2 = 0;
        int res = 1;
        for (int i = 1; i < len; i++) {
            cnt2++;
            sum2+=grades[i];
            if (cnt2 > cnt1 && sum2 > sum1) {
                res++;
                cnt1 = cnt2;
                sum1 = sum2;
                cnt2 = 0;
                sum2 = 0;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}


