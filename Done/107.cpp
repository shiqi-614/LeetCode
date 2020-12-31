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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > res;
    void dfs(TreeNode* node, int depth) {
        if (node == NULL) return;
        if (res.size() <= depth) {
            res.push_back(vector<int>());
        }
        res[depth].push_back(node->val);

        if (node->left) dfs(node->left, depth + 1);
        if (node->right) dfs(node->right, depth + 1);
        
    }
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        dfs(root, 0);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    return 0;
}

