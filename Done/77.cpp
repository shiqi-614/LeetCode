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
    vector<vector<int> > res;
    vector<int> data;
    void dfs(int n, int k) {
        if (n == 0 || k == 0) {
            if (k == 0) {
                vector<int> tmp(data.begin(), data.end());
                reverse(tmp.begin(), tmp.end());
                res.push_back(tmp);
            }
        } else {
            dfs(n - 1, k);
            data.push_back(n);
            dfs(n - 1, k - 1);
            data.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        dfs(n, k);
        return res;
    }
};
int main()
{
    return 0;
}

