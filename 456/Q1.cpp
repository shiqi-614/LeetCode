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

typedef pair<int, int> PII;
typedef long long LL;

class Solution {
    public:
        vector<string> partitionString(string s) {
            int len = (int)s.length();
            set<string> st;
            vector<string> res;
            string cur = "";
            for (int i = 0; i < len; i++) {
                cur += s[i];
                if (st.find(cur) != st.end()) {
                } else {
                    st.insert(cur);
                    res.push_back(cur);
                    cur = "";
                }
            }
            return res;
        }
};


int main()
{
    return 0;
}

