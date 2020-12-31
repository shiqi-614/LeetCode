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
    vector<int> getCharCount(string chars) {
        vector<int> res(35, 0);
        for (int i = 0; i < (int)chars.length(); i++) {
            res[chars[i] -'a'] ++;
        }
        return res;
    }

    bool check(vector<int> chars, vector<int> word) {
        for (int i = 0; i < 32; i++) {
            if (chars[i] < word[i]) {
                return false;
            }
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        vector<int> data = getCharCount(chars);
        int res = 0;
        for (int i = 0; i < (int)words.size(); i++) {
            vector<int> cnts = getCharCount(words[i]);
            if (check(data, cnts)) {
                res += words[i].length();
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

