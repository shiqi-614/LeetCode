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
    map<int, int> H;
    void dfs(TreeNode* node, int depth) {
        if (node == NULL) {
            return;
        }
        if (H.find(depth) == H.end()) {
            H[depth] = 0;
        }
        H[depth] += node->val;

        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root, 1);

        map<int,int>::iterator it;
        int mi = (1<<30);
        int res = -1;
        for (it = H.begin(); it != H.end(); it++) {
            if (it->second < mi) {
                mi = it->second;
                res = it->first;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

