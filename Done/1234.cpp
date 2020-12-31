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

class Solution {
public:
    int getIdx(char chr) {
        if (chr == 'Q') return 0;
        else if (chr == 'W') return 1;
        else if (chr == 'E') return 2;
        else if (chr == 'R') return 3;
        return -1;
    }
    int getLftIdx(vector<vector<int> >& lft, int len) {
        int idx = 0;
        for (int i = 0; i < len; i++) {
            bool flag = false;
            for (int j = 0; j < 4; j++) {
                if (lft[j][i] > len / 4) {
                    flag = true;
                    break;
                }
            }
            if (!flag) idx = i;
            else break;
        }
        return idx;
    }

    int balancedString(string s) {
        int len = (int)s.length();
        if (len == 0) return 0;

        vector<vector<int> > lft(4, vector<int>(len, 0));
        vector<vector<int> > rht(4, vector<int>(len, 0));
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 4; j++) {
                if (i > 0) {
                    lft[j][i] = lft[j][i - 1];
                } 
            }
            lft[getIdx(s[i])][i]++;
        }

        for (int i = len - 1; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                if (i < len - 1) {
                    rht[j][i] = rht[j][i + 1];
                }
            }
            rht[getIdx(s[i])][i]++;
        }

        //for (int j = 0; j < 4; j++) {
            //cout<<rht[j][0]<<" ";
        //} cout<<endl;

        //for (int j = 0; j < 4; j++) {
            //cout<<lft[j][len-1]<<" ";
        //} cout<<endl;

        if (rht[0][0] == rht[1][0] && rht[0][0] == rht[2][0] && rht[0][0] == rht[3][0]) return 0;
        int res = len;
        int lftIdx = getLftIdx(lft, len);
        res = min(res, len - 1 - lftIdx);


        for (int i = len - 1; i >= 0; i--) {
            for (int j = 0; j < 4; j++) if (rht[j][i] > len / 4) {
                return res;
            }
            while(1 && lftIdx >= 0) {
                bool flag = false;
                for (int j = 0; j < 4; j++) {
                    if (rht[j][i] + lft[j][lftIdx] > len / 4) {
                        flag = true;
                        break;
                    }
                }
                if (flag) lftIdx--;
                else break;
            }
            res = min(res, (i - 1) - (lftIdx + 1) + 1);
        }

        return res;
    }
};

int main() {
    Solution s;
    cout<<s.balancedString("QWER")<<endl;
    cout<<s.balancedString("QQWE")<<endl;
    cout<<s.balancedString("QQQE")<<endl;
    cout<<s.balancedString("QQQQ")<<endl;
    cout<<s.balancedString("RERRRRERREWEWWEREERQWWQRQWWRQEEWWWQWRQWQRRWERWERQQWQRQWEEQEEREERQRWQRRQWEQWWQRQRQERQWERW")<<endl;
    return 0;
}

