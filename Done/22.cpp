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
    string current;
    vector<string> res;
    string stringPopBack(string str) {
        int len = (int)str.length();
        return str.substr(0, len - 1);
    }
    void dfs(int sum,int lft, int rht) {
        if (lft == 0 && rht == 0) {
            res.push_back(current);
        } else {
            if (lft > 0) {
                current = current + "(";
                dfs(sum + 1, lft - 1, rht);
                current = stringPopBack(current);
            }

            if (sum - 1 >= 0 && rht > 0) {
                current = current + ")";
                dfs(sum - 1, lft, rht - 1);
                current = stringPopBack(current);
            }
        }

    }
    vector<string> generateParenthesis(int n) {
        res.clear();
        dfs(0, n, n);
        return res;
    }
};

int main() {
    Solution s;
    vector<string> res = s.generateParenthesis(4);
    for (int i = 0; i < (int)res.size(); i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}

