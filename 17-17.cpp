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

const int N = 30;

struct TrieNode {
    TrieNode* next[N];
    TrieNode()
    {
        for (int i = 0; i < N; i++) {
            next[i] = NULL;
        }
        data.clear();
    }
    vector<int> data;
};
struct TrieTree {
    TrieNode* root;
    TrieTree()
    {
        this->root = new TrieNode();
    }
    void insert(string word, int idx)
    {
        int len = (int)word.length();
        TrieNode* current = root;
        for (int i = 0; i < len; i++) {
            int chr = word[i] - 'a';
            if (current->next[chr] == NULL) {
                current->next[chr] = new TrieNode();
            }
            current = current->next[chr];
        }
        current->data.push_back(idx);
    }
    vector<int> find(string big, int st)
    {
        int len = (int)big.length();
        TrieNode* current = root;
        vector<int> res;
        vector<int>::iterator it;
        for (int i = st; i < len; i++) {
            int chr = big[i] - 'a';
            if (current->next[chr] != NULL) {
                current = current->next[chr];
                if (current->data.size() > 0) {
                    for (int j = 0; j < (int)current->data.size(); j++) {
                        res.push_back(current->data[j]);
                    }
                }
            } else {
                return res;
            }
        }
        return res;
    }
} trie;
class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls)
    {
        vector<vector<int>> res((int)smalls.size(), vector<int>());
        for (int i = 0; i < (int)smalls.size(); i++) {
            cout << "insert:" << smalls[i] << " " << i << endl;
            trie.insert(smalls[i], i);
        }
        int len = (int)big.length();
        for (int i = 0; i < len; i++) {
            vector<int> tmp = trie.find(big, i);
            for (int j = 0; j < (int)tmp.size(); j++) {
                res[tmp[j]].push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    vector<string> smalls;
    smalls.push_back("is");
    smalls.push_back("ppi");
    smalls.push_back("hi");
    smalls.push_back("sis");
    smalls.push_back("i");
    smalls.push_back("ssippi");
    Solution s;
    vector<vector<int>> res = s.multiSearch("mississippi", smalls);
    for (int i = 0; i < (int)res.size(); i++) {
        for (int j = 0; j < (int)res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
