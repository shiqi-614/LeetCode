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
const int N = 31;
struct Node {
    bool flag;
    Node* nxt[2];
    Node()
    {
        flag = false;
        nxt[0] = NULL;
        nxt[1] = NULL;
    }
};
struct Trie {
    Node* root;
    void init()
    {
        root = new Node();
    }
    void insert(int val)
    {
        Node* cur = root;
        for (int i = N; i >= 0; i--) {
            int tmp = (val & (1 << i)) > 0;
            if (cur->nxt[tmp] == NULL) {
                cur->nxt[tmp] = new Node();
            }
            cur = cur->nxt[tmp];
        }
        cur->flag = true;
    }
    int query(LL val)
    {
        Node* cur = root;
        for (int i = N; i >= 0; i--) {
            int tmp = (val & (1LL << i)) > 0;
            if (cur->nxt[!tmp] != NULL) {
                cur = cur->nxt[!tmp];
                val ^= ((1 << i) * (!tmp));
            } else if (cur->nxt[tmp] != NULL) {
                cur = cur->nxt[tmp];
                val ^= ((1 << i) * (tmp));
            } else {
                return 0;
            }
        }
        return val;
    }
} trie;
class Solution {
public:
    int findMaximumXOR(vector<int>& nums)
    {
        trie.init();
        int len = (int)nums.size();
        int mx = 0;
        for (int i = 0; i < len; i++) {
            mx = max(mx, trie.query(nums[i]));
            // cout << "i:" << i << " nums:" << nums[i] << " " << mx << endl;
            trie.insert(nums[i]);
        }
        return mx;
    }
};

int main()
{
    int tmp[] = { 3, 10, 5, 25, 2, 8 };
    int len = sizeof(tmp) / sizeof(int);
    vector<int> data;
    for (int i = 0; i < len; i++) {
        data.push_back(tmp[i]);
    }
    Solution s;
    cout << s.findMaximumXOR(data) << endl;
    return 0;
}
