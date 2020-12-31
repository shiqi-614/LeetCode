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
    int maxRepOpt1(string text) {
        if ((int)text.length() == 0) {
            return 0;
        }

        vector<vector<PII> > data(30, vector<PII>());

        int len = (int)text.length();
        char chr = text[0];
        int st = 0;
        for (int i = 0; i < len; i++) {
            if (text[i] == chr) {
                continue;
            } else {
                data[chr-'a'].PB(MP(st, i - 1));
                st = i;
                chr = text[i];
            }
        }
        data[chr-'a'].PB(MP(st, len - 1));
        int mx = 0;
        for (int i = 0; i < 30; i++) {
            int tmp = (int)data[i].size();
            for (int j = 0; j < tmp; j++) {
                if (j + 1 < tmp && data[i][j].second + 2 == data[i][j + 1].first) {
                    if (data[i].size() > 2) {
                        mx = max(mx, data[i][j + 1].second - data[i][j].first + 1);
                    } else {
                        mx = max(mx, data[i][j + 1].second - data[i][j].first);
                        
                    }
                } else {
                    if (tmp > 1) {
                        mx = max(mx, data[i][j].second - data[i][j].first + 2);
                    } else {
                        mx = max(mx, data[i][j].second - data[i][j].first + 1);

                    }
                }
//                cout<<data[i][j].first<<" "<<data[i][j].second<<endl;
            }
        }
        return mx;
    }
};

int main() {
    Solution s;
    cout<<s.maxRepOpt1("ababa")<<endl;
    return 0;
}

