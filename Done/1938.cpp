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

const int N = 20;
struct TrieNode {
    int cnt;
    TrieNode* left;
    TrieNode* right;
    TrieNode()
    {
        cnt = 0;
        left = NULL;
        right = NULL;
    }
};

struct Trie {
    TrieNode* rt;
    Trie()
    {
        rt = new TrieNode();
    }
    void insert(int num)
    {
        TrieNode* now = rt;
        for (int i = N; i >= 0; i--) {
            if (num & (1 << i)) {
                if (!now->left) {
                    now->left = new TrieNode();
                }
                now = now->left;
            } else {
                if (!now->right) {
                    now->right = new TrieNode();
                }
                now = now->right;
            }
            now->cnt++;
        }
    }
    int query(int num)
    {
        TrieNode* now = rt;
        int mask = 0;
        for (int i = N; i >= 0; i--) {
            if (num & (1 << i)) {
                if (now->right && now->right->cnt) {
                    now = now->right;
                } else if (now->left && now->left->cnt) {
                    now = now->left;
                    mask |= (1 << i);
                }
            } else {
                if (now->left && now->left->cnt) {
                    now = now->left;
                    mask |= (1 << i);
                } else if (now->right && now->right->cnt) {
                    now = now->right;
                }
            }
        }
        cout << "num:" << num << " mask:" << mask << endl;
        return num ^ mask;
    }
    void remove(int num)
    {
        TrieNode* now = rt;
        for (int i = N; i >= 0; i--) {
            if (num & (1 << i)) {
                now = now->left;
            } else {
                now = now->right;
            }
            now->cnt--;
        }
    }
};

class Solution {
public:
    map<int, vector<PII>> H;
    vector<int> res;
    vector<vector<int>> adj;
    void dfs(int now, Trie& trie)
    {
        if (H.find(now) != H.end()) {
            vector<PII> query = H[now];
            for (int i = 0; i < (int)query.size(); i++) {
                PII pi = query[i];
                int mx = trie.query(pi.first);
                res[pi.second] = mx;
            }
        }

        int len = (int)adj[now].size();
        for (int i = 0; i < len; i++) {
            int v = adj[now][i];
            trie.insert(v);
            dfs(v, trie);
            trie.remove(v);
        }
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries)
    {
        int len = (int)parents.size();
        adj.resize(len, vector<int>());
        H.clear();
        Trie trie;

        int root = -1;
        for (int i = 0; i < len; i++) {
            int v = parents[i];
            if (v != -1) {
                adj[v].push_back(i);
            } else {
                root = i;
            }
        }
        len = (int)queries.size();
        res.resize(len, -1);
        for (int i = 0; i < len; i++) {
            int node = queries[i][0];
            int val = queries[i][1];
            if (H.find(node) == H.end()) {
                H.insert(MP(node, vector<PII>()));
            }
            H[node].push_back(MP(val, i));
        }
        trie.insert(root);
        dfs(root, trie);
        return res;
    }
};

int main()
{
    return 0;
}
