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

const int N = 10000;

class Solution {
public:
    LL num[N];
    int res;
    vector<int> data;
    void dfs(int remain, int idx) {
        if (remain == 0) {
            if (res == -1) {
                res = (int)data.size(); 
            } else {
                res = min(res, (int)data.size());
            }
        } else if (res != -1) {
            return;
        } else if (idx == 0) {
            return;
        } else {
            if (res != -1 && data.size() > res) return;
            if (remain >= num[idx]) {
                data.push_back(num[idx]);
                dfs(remain - num[idx], idx - 1);
                data.pop_back();
            }
            dfs(remain, idx - 1);
        }
    }
    int findMinFibonacciNumbers(int k) {
        num[0] = 1;
        num[1] = 1;
        int idx = 1;
        while(num[idx] < k && idx < N) {
            num[idx + 1] = num[idx] + num[idx - 1];
            idx++;
        }
        res = -1;
        dfs(k, idx);
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.findMinFibonacciNumbers(374602)<<endl;
    return 0;
}

