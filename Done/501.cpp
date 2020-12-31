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
    int cnt;
    int val;
    int mx;
    vector<int> res;
    void update() {
        if (cnt > mx) {
            res.clear();
            res.push_back(val);
            mx = cnt;
        } else if (cnt == mx) {
            res.push_back(val);
        }
    }
    void dfs(TreeNode* root) {
        if (root->left) {
            dfs(root->left);
        }
        if (root->val != val) {
            update();
            val = root->val;
            cnt = 1;
        } else {
            cnt++;
        }
        if(root->right) dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if (root == NULL) return res;
        mx = 0;
        cnt = -1;
        val = -1;
        dfs(root);
        update();
        return res;
    }
};

int main() {
    return 0;
}

