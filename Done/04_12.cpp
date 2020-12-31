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
    map<int, int> H;
    int sum;
    int res;
    void dfs(TreeNode* current, int pathSum) {
        if(current == NULL) {
            return;
        } else {
            pathSum += current->val;
//            cout<<pathSum<<" prev:"<<pathSum - sum<<endl;
            if (H.find(pathSum - sum) != H.end()) {
                res += H[pathSum - sum];
            }
            if (pathSum == sum) {
                res++;
            }
            H[pathSum]++;
            dfs(current->left, pathSum);
            dfs(current->right, pathSum);
            H[pathSum]--;
        }
    }
    int pathSum(TreeNode* root, int sum) {
        this->res = 0;
        this->sum = sum;
        dfs(root, 0);
        return res;
    }
};

int main() {
    return 0;
}

