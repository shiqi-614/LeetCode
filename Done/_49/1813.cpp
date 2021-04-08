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

class Solution {
public:
    int len1;
    int len2;
    int getPrefix(vector<string> s1, vector<string> s2)
    {
        int len = 0;
        for (int i = 0; i < len2; i++) {
            if (s1[i] == s2[i]) {
                len++;
            } else {
                break;
            }
        }
        return len;
    }

    int getPosfix(vector<string> s1, vector<string> s2)
    {
        int len = 0;
        for (int i = 0; i < len2; i++) {
            if (s1[len1 - 1 - i] == s2[len2 - 1 - i]) {
                len++;
            } else {
                break;
            }
        }
        return len;
    }

    vector<string> getWords(string sentence1)
    {
        vector<string> res;
        string cur = "";
        for (int i = 0; i < (int)sentence1.length(); i++) {
            if (sentence1[i] == ' ') {
                res.push_back(cur);
                cur = "";
            } else {
                cur += sentence1[i];
            }
        }
        if (cur.length()) {
            res.push_back(cur);
        }
        return res;
    }
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        if (sentence1 == sentence2) {
            return true;
        }

        len1 = (int)sentence1.length();
        len2 = (int)sentence2.length();
        if (sentence1.length() < sentence2.length()) {
            swap(sentence1, sentence2);
        }

        vector<string> s1 = getWords(sentence1);
        vector<string> s2 = getWords(sentence2);
        len1 = (int)s1.size();
        len2 = (int)s2.size();

        int pre = getPrefix(s1, s2);
        int pos = getPosfix(s1, s2);
        if ((pre == len2 && pos == 0) || (pos == len2 && pre == 0)) {
            return true;
        } else {
            return (pre + pos) == len2;
        }
    }
};

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    return 0;
}
