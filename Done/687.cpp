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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
public:
    //map<TreeNode*, int> dp;
    //int dfs(TreeNode* node)
    //{
    //if (node == NULL)
    //return 0;
    //else {
    //if (dp.find(node) == dp.end()) {
    //dp[node] = 0;
    //} else {
    //return dp[node];
    //}
    //int mx = 1;
    //if (node->left && node->left->val == node->val)
    //mx = max(mx, 1 + dfs(node->left));
    //if (node->right && node->right->val == node->val)
    //mx = max(mx, 1 + dfs(node->right));
    //dp[node] = mx;
    //return mx;
    //}
    //}
    //int longestUnivaluePath(TreeNode* root)
    //{
    //if (root == NULL)
    //return 0;
    //else {
    //int mx = 0;
    //if (root->left)
    //mx = max(mx, longestUnivaluePath(root->left));
    //if (root->right)
    //mx = max(mx, longestUnivaluePath(root->right));
    //int cnt = 0;
    //if (root->left && root->left->val == root->val) {
    //cnt += dfs(root->left);
    //}
    //if (root->right && root->right->val == root->val) {
    //cnt += dfs(root->right);
    //}
    //return max(cnt, mx);
    //}
    //}
    int ans;
    int dfs(TreeNode* node)
    {
        if (node == NULL)
            return 0;
        else {
            int lft = dfs(node->left);
            int rht = dfs(node->right);
            int lftEdge = 0;
            int rhtEdge = 0;
            if (node->left && node->left->val == node->val) {
                lftEdge = lft + 1;
            }
            if (node->right && node->right->val == node->val) {
                rhtEdge = rht + 1;
            }
            ans = max(ans, lftEdge + rhtEdge);
            return max(lftEdge, rhtEdge);
        }
    }
    int longestUnivaluePath(TreeNode* root)
    {
        ans = 0;
        dfs(root);
        return ans;
    }
};

int main()
{
    return 0;
}
