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
    bool find;
    void dfs(TreeNode* s, TreeNode* t) {
        if (find) return;
        if (s -> val == t -> val) {
            find |= check(s, t);
        } 
        if (s -> left) dfs(s -> left, t);
        if (s -> right) dfs(s -> right, t);
    }

    bool check(TreeNode* s, TreeNode* t) {
        if (s->val != t->val) return false;

        bool flag = true;
        if (s -> left && t -> left) {
            flag = (flag & check(s -> left, t -> left));
        } else if (s -> left == NULL && t -> left == NULL) {
            flag = (flag & 1);
        } else {
            flag = false;
        }

        if (s -> right && t -> right) {
            flag = (flag & check(s -> right, t -> right));
        } else if (s -> right == NULL && t -> right == NULL) {
            flag = (flag & 1);
        } else {
            flag = false;
        }

        return flag;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        this->find = false;
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        dfs(s, t);
        return find;
    }
};

int main() {
    return 0;
}

