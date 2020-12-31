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

class Solution {
public:
    bool isPali(string s) {
        int len = (int)s.length();
        int st = 0;
        int ed = len - 1;
        while(st < ed) {
            if (s[st] != s[ed]) return false;
            st++; ed--;
        }
        return true;
    }

    bool check(string a, string b) {
        int len = (int)a.length();
        int preLen = 0;
        for (int i = 0; i < len; i++) {
            if (a[i] == b[len - 1 - i]) {
                continue;
            } else {
                preLen = i;
                break;
            }
        }
        cout<<"preLen:"<<preLen<<endl;
        if (preLen == 0) return false;

        cout<<"len is:"<<(len - preLen * 2) / 2<<endl;
        bool flag1 = true;
        for (int i = 0; i < (len - preLen * 2) / 2; i++) {
            if (b[preLen + i] != b[len - 1 - preLen - i]) {
                cout<<preLen + i<<" "<<len - 1 - preLen - i<<endl;
                cout<<b[preLen + i] <<" "<< b[len - 1 - preLen - i]<<endl;
                flag1 = false;
                break;
            }
        }
        bool flag2 = false;
        for (int i = 0; i < (len - preLen * 2) / 2; i++) {
            if (a[preLen + i] != a[len - 1 - preLen - i]) {
                cout<<"two"<<endl;
                cout<<preLen + i<<" "<<len - 1 - preLen - i<<endl;
                cout<<a[preLen + i] <<" "<< a[len - 1 - preLen - i]<<endl;
                flag2 =  false;
                break;
            }
        }
        return flag1 || flag2;
    }
    bool checkPalindromeFormation(string a, string b) {
        if (isPali(a) || isPali(b)) {
            return true;
        }

        if (check(a, b) || check(b, a)) {
            cout<<"ischeck"<<endl;
            return true;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (check(b, a) || check(a, b)) return true;
        return false;
    }
};
int main()
{
    Solution s;
    //cout<<s.checkPalindromeFormation("x", "y")<<endl;
    //cout<<s.checkPalindromeFormation("abdef", "fecab")<<endl;
    //cout<<s.checkPalindromeFormation("abdxef", "fewcab")<<endl;
    //cout<<s.checkPalindromeFormation("abdwef", "fewcab")<<endl;
    //cout<<s.checkPalindromeFormation("pvhmupgqeltozftlmfjjde", "yjgpzbezspnnpszebzmhvp")<<endl;
    //cout<<s.checkPalindromeFormation("ulacfd", "jizalu")<<endl;
    //cout<<s.checkPalindromeFormation("ulacfddef", "efgabaalu")<<endl;
//    cout<<s.checkPalindromeFormation("aejbaalflrmkswrydwdkdwdyrwskmrlfqizjezd", "uvebspqckawkhbrtlqwblfwzfptanhiglaabjea")<<endl;
cout<<s.checkPalindromeFormation("cdeoo", "oooab")<<endl;
    return 0;
}

