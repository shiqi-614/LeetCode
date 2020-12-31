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
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int len = (int)arr.size();
        int idx = 0;
        int piecesLen = (int)pieces.size();
        while(idx < len) {
            int target = -1;
            for (int j = 0; j < piecesLen; j++) {
                if (pieces[j][0] == arr[idx]) {
                    break;
                }
            }
            if (target == -1) return false;
            for (int j = 0; j < (int)pieces[target].size(); j++) {
                if (arr[idx] == pieces[target][j]) {
                    idx++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}

