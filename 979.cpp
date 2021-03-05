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
    void dfs(TreeNode* node, int& extra_cnt, int& lack_cnt, int& res)
    {
        if (node == NULL) {
            return;
        } else {
            int extra_lft_cnt = 0;
            int lack_lft_cnt = 0;
            int res_lft = 0;

            int extra_rht_cnt = 0;
            int lack_rht_cnt = 0;
            int res_rht = 0;

            dfs(node->left, extra_lft_cnt, lack_lft_cnt, res_lft);
            dfs(node->right, extra_rht_cnt, lack_rht_cnt, res_rht);

            extra_cnt = extra_lft_cnt + extra_rht_cnt;
            lack_cnt = lack_lft_cnt + lack_rht_cnt;
            res = res_lft + res_rht + extra_cnt + lack_cnt;

            if (node->val > 1) {
                extra_cnt += node->val - 1;
            } else if (node->val == 0) {
                if (extra_cnt > 0) {
                    extra_cnt--;
                } else {
                    lack_cnt++;
                }
            }

            if (extra_cnt > lack_cnt) {
                extra_cnt -= lack_cnt;
                lack_cnt = 0;
            } else {
                lack_cnt -= extra_cnt;
                extra_cnt = 0;
            }

            cout << "node->val:" << node->val << " extra_cnt:" << extra_cnt << " lack_cnt:" << lack_cnt << " res:" << res << endl;
        }
    }
    int distributeCoins(TreeNode* root)
    {
        int extra_cnt = 0;
        int lack_cnt = 0;
        int res = 0;
        dfs(root, extra_cnt, lack_cnt, res);
        return res;
    }
};

int main()
{
    return 0;
}
