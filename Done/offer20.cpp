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
    bool isInteger(string s, int st, int ed) {
//        cout<<"isInteger:"<<st<<" ed:"<<ed<<endl;
        if (st > ed) return false;
        for (int i = st; i <= ed; i++) {
            if (!(s[i] >= '0' && s[i] <= '9')) {
                return false;
            }
        }
        return true;
    }
    bool isIntegerWithChacater(string s, int st, int ed) {
//        cout<<"isIntegerWithChacater:"<<st<<" ed:"<<ed<<endl;
        if (st > ed) return false;

        if (s[st] == '+' || s[st] == '-') st++;
        return isInteger(s, st, ed);
    }

    bool isPureNumber(string s, int st, int ed) {
//        cout<<"isPureNumber:"<<st<<" ed:"<<ed<<endl;
        if (s[st] == '.') {
            st++;
            return isInteger(s, st, ed);
        }
        else if (s[ed] == '.') {
            ed--;
            return isInteger(s, st, ed);
        } else {
            for (int i = st; i <= ed; i++) {
                if (s[i] == '.') {
                    return isInteger(s, st, i - 1) && isInteger(s, i + 1, ed);
                }
            }
            return isInteger(s, st, ed);
        }
    }
    bool isNumberWithChacater(string s, int st, int ed) {
//        cout<<"isNumberWithChacater:"<<st<<" ed:"<<ed<<endl;

        if (st > ed) return false;

        if (s[st] == '+' || s[st] == '-') {
            st++;
        } 
        return isPureNumber(s, st, ed);
    }

    bool isNumber(string s) {
        int len = (int)s.length();
        int st = 0;
        int ed = len - 1;

        while(st < len && s[st] == ' ') st++;
        while(ed >= 0 && s[ed] == ' ') ed--;
        s = s.substr(st, ed - st + 1);
//cout<<"after:"<<s<<endl;

        len = (int)s.length();

        for (int i = 0; i < len; i++) {
            if (s[i] == 'e' || s[i] == 'E') {
                if (isNumberWithChacater(s, 0, i - 1) && isIntegerWithChacater(s, i + 1, len - 1)) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return isNumberWithChacater(s, 0, len - 1);
    }
};

int main()
{
    Solution s;
    cout<<s.isNumber("1 ")<<endl;;
    cout<<s.isNumber("1. ")<<endl;;
    cout<<s.isNumber("-1. ")<<endl;;
    cout<<s.isNumber(".1 ")<<endl;;
    cout<<s.isNumber(" 1 ")<<endl;;
    cout<<s.isNumber("+199")<<endl;;
    cout<<s.isNumber("5e2")<<endl;
    cout<<s.isNumber("-123")<<endl;
    cout<<s.isNumber("3.1415")<<endl;
    cout<<s.isNumber("-1E-15")<<endl;
    cout<<s.isNumber("0123")<<endl;

    cout<<"false"<<endl;
    cout<<s.isNumber("e1. ")<<endl;;
    cout<<s.isNumber(".34.2")<<endl;;
    cout<<s.isNumber("12e")<<endl;
    cout<<s.isNumber("1a3.14")<<endl;
    cout<<s.isNumber("1.3.14")<<endl;
    cout<<s.isNumber("+-5")<<endl;
    cout<<s.isNumber("12e+5.4")<<endl;

    return 0;
}

