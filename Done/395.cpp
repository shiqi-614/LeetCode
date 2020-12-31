#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;

class Solution {
public:
    int longestSubstring(string s, int K) {
        int len = (int)s.length();
        if (K == 1) return len;

        vector<vector<int> > cnt(26, vector<int>(len, 0));

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 26; j++) {
                if (i > 0) {
                    cnt[j][i] = cnt[j][i - 1];
                }
                if (s[i] - 'a' == j) {
                    cnt[j][i]++;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                bool flag = true;
                for (int k = 0; k < 26; k++) {
                    int tmp = i - 1 >= 0 ? cnt[k][i - 1] : 0;
                    if (cnt[k][j] - tmp >= K || cnt[k][j] == tmp) {
                    } else {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
//                    cout<<i<<" "<<j<<endl;
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout<<s.longestSubstring("aaabb", 3)<<endl;
    //cout<<s.longestSubstring("ababbc", 2)<<endl;
    //cout<<s.longestSubstring("weitong", 2)<<endl;
    //cout<<s.longestSubstring("ababacb", 2)<<endl;
    //cout<<s.longestSubstring("ababacb", 3)<<endl;
    //cout<<s.longestSubstring("bbaaacbd", 3)<<endl;
    cout<<s.longestSubstring("aaabbbcdefcdefcde", 3)<<endl;
    return 0;
}

