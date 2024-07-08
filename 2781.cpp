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

typedef long long LL;
typedef pair<int, int> PII;

const int N = 26;
const int M = 10;

struct TrieNode {
    bool isWord;
    TrieNode* next[N];
    TrieNode()
    {
        isWord = false;
        for (int i = 0; i < N; i++) {
            next[i] = NULL;
        }
    }
};

struct TrieTree {
    TrieNode* root;
    TrieTree()
    {
        root = new TrieNode();
    }
    void insert(string& s)
    {
        TrieNode* cur = root;
        for (auto& chr : s) {
            int idx = chr - 'a';
            if (cur->next[idx] == NULL) {
                cur->next[idx] = new TrieNode();
            }
            cur = cur->next[idx];
        }
        cur->isWord = true;
    }
    int query(string& str, int st, int ed)
    {
        TrieNode* cur = root;
        for (int i = st; i < ed; i++) {
            int chr = str[i] - 'a';
            if (cur->next[chr] != NULL) {
                cur = cur->next[chr];
                if (cur->isWord) {
                    return i;
                }
            } else {
                return -1;
            }
        }
        return -1;
    }
};

struct Node {
    int st;
    int ed;
    Node() { }
    Node(int st, int ed)
        : st(st)
        , ed(ed)
    {
    }
    bool operator<(const Node& b) const
    {
        if (b.ed != ed) {
            return ed < b.ed;
        } else {
            return st < b.st;
        }
    }
};

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden)
    {
        TrieTree trie;
        for (auto& str : forbidden) {
            trie.insert(str);
            cout << "insert:" << str << endl;
        }

        int len = (int)word.length();
        vector<int> endPos(len, -1);
        for (int i = 0; i < len; i++) {
            int pos = trie.query(word, i, min(i + M, len));
            endPos[i] = pos;
            cout << "query:" << i << " pos:" << endPos[i] << endl;
        }

        int lft = 0;
        int rht = 0;
        priority_queue<Node> que;

        int res = 0;
        while (rht < len) {
            if (endPos[rht] != -1) {
                que.push(Node(rht, endPos[rht]));
            }
            while (!que.empty() && que.top().ed == rht) {
                if (que.top().st < lft) {
                    que.pop();
                } else if (que.top().st >= lft) {
                    lft = que.top().st + 1;
                    que.pop();
                }
            }
            res = max(res, rht - lft + 1);
            rht++;
        }
        return res;
    }
};

int main()
{
    return 0;
}
