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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> res;
    void dfs(TreeNode* node, string path) {
        if (node->left == NULL && node->right == NULL) {
            res.push_back(path);
        } else {
            if (node->left) dfs(node->left, path + "->" + to_string(node->left->val));
            if (node->right) dfs(node->right, path + "->" + to_string(node->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root) dfs(root, to_string(root->val));
        return res;
    }
};
int main()
{
    return 0;
}

