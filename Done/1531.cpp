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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int N = 102;
class Solution {
public:
    int len;
    string s;
    int dp[N][N];
    int prefix[N][N];
    int getCost(int num) {
        if (num == 1) return 1;
        else if (num >= 2 && num <= 9) return 2;
        else if (num >= 10 && num <= 99) return 3;
        else return 4;
    }
    void getPrefix() {
        for (int i = 0; i < len; i++) {
            int cnt = 0;
            int cost = 0;
            for (int j = i; j >= 0; j--) {
                if (s[j] == s[i]) {
                    cnt++;
                } else {
                    prefix[i][cost] = cnt;
                    cost++;
                }
            }
            prefix[i][cost] = cnt;
        }
    }

    int dfs(int idx, int remain) {
        if (idx == -1) {
            return 0;
        } else {
            int &res = dp[idx][remain];
            if (res != -1) return res;
            res = len + 1;
            for (int i = 0; i <= remain; i++) if (prefix[idx][i] != -1) {
                res = min(res, dfs(idx - i - prefix[idx][i], remain - i) + getCost(prefix[idx][i]));
            }
            if (remain > 0) {
                res = min(res, dfs(idx - 1, remain - 1));
            }
//            cout<<"idx:"<<idx<<" remain:"<<remain<<" res:"<<res<<endl;
            return res;
        }
    }

    int getLengthOfOptimalCompression(string s, int remain) {
        this->s = s;
        this->len = (int)s.length();
        memset(dp, -1, sizeof(dp));
        memset(prefix, -1, sizeof(prefix));
        
        getPrefix();
        return dfs(len - 1, remain);
    }
};


int main()
{
    Solution s;
    cout<<s.getLengthOfOptimalCompression("aaabcccd", 2)<<endl;
    cout<<s.getLengthOfOptimalCompression("aabbaa", 2)<<endl;
    cout<<s.getLengthOfOptimalCompression("aaaaaaaaaaa", 2)<<endl;
    cout<<s.getLengthOfOptimalCompression("aaaaaaaaaaa", 2)<<endl;
    return 0;
}

"aaabcccd"
2
"aabbaa"
2
"aaaaaaaaaaa"
2
"abc"
0
"bababbaba"
1
"babababa"
0
"dbfdfhgacceefebibedcieebchcgaeigiiidifiegbchcgbfiichafhhgiahdeicegbbbfbbeficgefdebhbcddcebhaccdaigfe"
31
"denammdfegkjechilepbckbhkahhhhpkoigjdnboblaoejdjhhgcngpicimbpnhjmafbajmjhffhkeolefpimjhahcnnndjnmknd"
42
"baccabccccaabcbcbcbabbccbabccacbabccbaaccaabcaaabccaaabacabaccbbacbbcccacaacabcabbcaaaaaaabcbcbbbbbb"
12
