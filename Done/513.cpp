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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int depth;
    int value;

    void dfs(TreeNode* node, int current) {
        if (node == NULL) {
            return;
        }
        if (depth < current) {
            depth = current;
            value = node->val;
        }
        dfs(node->left, current + 1);
        dfs(node->right, current + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        this->depth = 0;
        dfs(root, 0);
        return value;
    }
};

int main() {
    return 0;
}

