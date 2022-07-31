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
    bool check(vector<int>& data1, vector<int>& data2) {
        int n = (int)data1.size();
        for (int i = 0; i < n; i++) {
            if (data1[i] != data2[i]) {
                return false;
            }
        }
        return true;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<vector<int>> row;
        for (int i = 0; i< n; i++ ) {
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                tmp.push_back(grid[j][i]);
            }
            row.push_back(tmp);
        }
        
        int res = 0;
        for (int i = 0;i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (check(grid[i], row[j])) {
                    res++;
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}


