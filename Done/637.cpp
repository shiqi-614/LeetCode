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
    vector<LL> sum;
    vector<LL> cnt;
    void dfs(TreeNode* node, int depth) {
        if (node == NULL) return;
        if (depth + 1> (int)sum.size()) {
            sum.push_back(0);
            cnt.push_back(0);
        }
        sum[depth] += node->val;
        cnt[depth] += 1;
        if (node -> left) dfs(node->left, depth + 1);
        if (node -> right) dfs(node->right, depth + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        sum.clear();
        cnt.clear();
        dfs(root, 0);
        int len = (int)sum.size();
        vector<double> res;
        for (int i = 0; i < len; i++) {
            res.push_back(sum[i] * 1.0 / cnt[i]);
        }
        return res;
    }
};

int main()
{
    return 0;
}

