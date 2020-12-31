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
    map<int, vector<int> > H;
    void dfs(TreeNode* cur, int depth) {
        if (cur == NULL) {
            return;
        }

        if (H.find(depth) == H.end()) {
            H.insert(make_pair(depth, vector<int>()));
        }
        H[depth].push_back(cur->val);
        dfs(cur->left, depth + 1);
        dfs(cur->right, depth + 1);
    }
    vector<vector<int> > levelOrder(TreeNode* root) {
        dfs(root, 0);
        vector<vector<int> > res;

        map<int, vector<int> >::iterator it;
        for (it = H.begin(); it != H.end(); it++) {
            int key = it->first;
            vector<int> data = it->second;
            if (key % 2) {
                reverse(data.begin(), data.end());
            }
            res.push_back(data);
        }
        return res;
    }
};

int main() {
    return 0;
}

