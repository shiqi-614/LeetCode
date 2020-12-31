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

bool isPalindrom(string str) {
    string tmp = str;
    reverse(tmp.begin(), tmp.end());
    return tmp == str;
}

struct TrieNode {
    set<int> indexs;
    TrieNode* next[30];
    TrieNode() {
        indexs.clear();
        for (int i = 0; i < 30; i++) {
            next[i] = NULL;
        }
    }
};

struct TrieTree {
    TrieNode* root;
    TrieTree() {
        root = new TrieNode();
    }
    void insert(string str, int idx) {
        int len = (int)str.length();
        TrieNode* current = root;

        if (isPalindrom(str)) {
            root->indexs.insert(idx);
        }

        for (int i = 0; i < len; i++) {
            if (current -> next[str[i]-'a'] == NULL) {
                current -> next[str[i]-'a'] = new TrieNode();
            }
            current->indexs.insert(idx);
            current = current->next[str[i]-'a'];
        }
        current->indexs.insert(idx);
    }

    set<int> query(string str) {
        set<int> res;
        int len = (int)str.length();
        TrieNode* current = root;

        for (int i = 0; i < len; i++) {
            if (current -> next[str[i]-'a'] != NULL) {
                current = current -> next[str[i] - 'a'];
            } else {
                return res;
            }
        }

        res.insert(current->indexs.begin(), current->indexs.end());
        return res;
    }
};

class Solution {
public:
    bool judge(string s1, string s2) {
        string s = s1 + s2;
        return isPalindrom(s);
    }

    set<PII> getPairs(vector<string>& words, vector<string>& rev, bool flag) {
        TrieTree trie;
        int len = (int)words.size();
        for (int i = 0; i < len; i++) {
            trie.insert(rev[i], i);
        }
        set<PII> pairs;
        for (int i = 0; i < len; i++) {
            set<int> res = trie.query(words[i]);
            int resLen = (int)res.size();
            set<int>::iterator it;
            for (it = res.begin(); it != res.end(); it++) {
                int idx = *it;
//                cout<<"pair:"<<i<<" "<<idx<<endl;
                if (i != idx && judge(words[i], words[idx])) {
                    if (flag == 0) {
                        pairs.insert(MP(i, idx));
                    } else {
                        pairs.insert(MP(idx, i));
                    }
                }
            }
        }
        return pairs;

    }
    vector<vector<int> > palindromePairs(vector<string>& words) {
        int len = (int)words.size();
        vector<string> rev = words;
        for (int i = 0; i < len; i++) {
            reverse(rev[i].begin(), rev[i].end());
//            cout<<words[i]<<" rev:"<<rev[i]<<endl;
        }
        set<PII> pairs1 = getPairs(words, rev, 0);
        set<PII> pairs2 = getPairs(rev, words, 1);
        pairs1.insert(pairs2.begin(), pairs2.end());

        vector<vector<int> > output;
        set<PII>::iterator it;
        for (it = pairs1.begin(); it != pairs1.end(); it++) {
            vector<int> data;
            data.PB(it->first);
            data.PB(it->second);
            output.PB(data);
        }
        return output;
    }
};

int main() {
    vector<string> data;
    //data.PB("abcd");
    //data.PB("dcba");
    //data.PB("lls");
    //data.PB("s");
    //data.PB("sssll");
    //data.PB("a");
    //data.PB("");
    data.PB("a");
    data.PB("b");
    data.PB("c");
    data.PB("ab");
    data.PB("ac");
    data.PB("aa");
   
    Solution s;
    vector<vector<int> > res = s.palindromePairs(data);
    for (int i = 0; i < (int)res.size(); i++) {
        cout<<res[i][0]<<" "<<res[i][1]<<endl;
    }
    return 0;
}

