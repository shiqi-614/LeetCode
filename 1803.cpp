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

struct TrieNode {
    int cnt;
    TrieNode* nxt[2];
    TrieNode()
    {
        cnt = 0;
        nxt[0] = NULL;
        nxt[1] = NULL;
    }
};

struct Trie {
    TrieNode* root;
    void init()
    {
        root = new TrieNode();
    }
    void insert(int val)
    {
        TrieNode* cur = root;
        for (int i = 16; i >= 0; i--) {
            int idx = ((val & (1 << i)) > 0);
            if (cur->nxt[idx] == NULL) {
                cur->nxt[idx] = new TrieNode();
            }
            cur = cur->nxt[idx];
            cur->cnt++;
        }
    }
    int query(int val, int limit)
    {
        TrieNode* cur = root;
        int res = 0;
        for (int i = 16; i >= 0; i--) {
            if (cur == NULL) {
                break;
            }
            int bitVal = ((val & (1 << i)) > 0);
            int bitLimit = ((limit & (1 << i)) > 0);
            if (bitLimit) {
                if (bitVal) {
                    if (cur->nxt[1] != NULL) {
                        res += cur->nxt[1]->cnt;
                    }
                    cur = cur->nxt[0];
                } else {
                    if (cur->nxt[0] != NULL) {
                        res += cur->nxt[0]->cnt;
                    }
                    cur = cur->nxt[1];
                }
            } else {
                if (bitVal) {
                    cur = cur->nxt[1];
                } else {
                    cur = cur->nxt[0];
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high)
    {
        Trie trie;
        trie.init();
        int len = (int)nums.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            int tmp = trie.query(nums[i], high + 1) - trie.query(nums[i], low);
            res += tmp;
            cout << "i:" << i << " tmp:" << tmp << " " << trie.query(nums[i], high + 1) << " " << trie.query(nums[i], low) << endl;
            trie.insert(nums[i]);
        }
        return res;
    }
};
int main()
{
    vector<int> data;
    int tmp[] = { 1, 4, 2, 7 };
    // int tmp[] = { 9, 8, 4, 2, 1 };
    int len = (int)sizeof(tmp) / sizeof(int);
    for (int i = 0; i < len; i++) {
        data.push_back(tmp[i]);
    }
    Solution s;
    cout << s.countPairs(data, 2, 6) << endl;

    return 0;
}
