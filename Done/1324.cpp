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
    vector<string> getWords(string s) {
        vector<string> res;
        string tmp = "";
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] != ' ') {
                tmp += s[i];
            } else {
                if (tmp.length()) {
                    res.push_back(tmp);
                } 
                tmp = "";
            }
        }
        if (tmp.length()) {
            res.push_back(tmp);
        }
        return res;
    }

    vector<string> formatRes(vector<string> res) {
        
        vector<string> output;
        for (int i = 0; i < (int)res.size(); i++) {

            string lastOne = res[i];
            int idx;
            for (int i = (int)lastOne.length() - 1; i >= 0; i--) {
                if (lastOne[i] == ' ') {
                    continue;
                } else {
                    idx = i; break;
                }
            }
            lastOne = lastOne.substr(0, idx + 1);
            output.push_back(lastOne);
        }
        return output;

    }
    vector<string> printVertically(string s) {
        vector<string> words = getWords(s);
        int mx = 0;
        for (int i = 0; i < (int)words.size(); i++) {
            mx = max(mx, (int)words[i].length());
        }
        vector<string> res(mx, "");
        for (int i = 0; i < (int)words.size(); i++) {
            for (int j = 0; j < mx; j++) {
                if (j < (int)words[i].length()) {
                    res[j]+=words[i][j];
                } else {
                    res[j] += ' ';
                }
            }
        }

        vector<string> output = formatRes(res);
        return output;
        
    }
};

int main() {
    return 0;
}

