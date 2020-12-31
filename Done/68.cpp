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
    TreeNode* res;
    
    int dfs(TreeNode* current, TreeNode* p, TreeNode* q) {
        if (current == NULL) {
            return 0;
        }
        int cnt = 0;
        if (current == p) {
            cnt++;
        }
        if (current == q) {
            cnt++;
        }
        cnt += dfs(current->left, p, q);
        cnt += dfs(current->right, p, q);
        if (cnt == 2 && res == NULL) {
            res = current;
        }
        return cnt;
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
};

int main() {
    return 0;
}

