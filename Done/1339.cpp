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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;


const LL MOD = 1e9 + 7;

class Solution {
public:
    int total;
    LL res;
    LL delta;
    int getTotal(TreeNode* root) {
        if (root == NULL) return 0;
        else {
            int sum = 0;
            sum += root -> val;
            if (root -> left) sum += getTotal(root->left);
            if (root -> right) sum += getTotal(root->right);
            root->val = sum;
            return sum;
        }
    }

    void getRes(TreeNode* root) {
        if (root == NULL) return;
        else {
            int sum = root -> val;
            LL tmp1 = total - sum;
            LL tmp2 = sum;
            
            res = max(res, tmp1 * 1LL * tmp2);
            if (abs(tmp1 - tmp2) < delta) {
                delta = abs(tmp1 - tmp2);
                res = (tmp1 * tmp2) % MOD;
            }
            if (root -> left) getRes(root->left);
            if (root -> right) getRes(root->right);
        }
        
    }


    int maxProduct(TreeNode* root) {
        delta = 1<<30;
        total = getTotal(root);
        getRes(root);
        return int(res % MOD);
    }
};

int main() {
    return 0;
}

