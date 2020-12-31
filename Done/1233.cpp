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
    bool isStartWith(string str1, string str2) {
        int len1 = (int)str1.length();
        int len2 = (int)str2.length();
        if (len1 < len2) {
            for (int i = 0; i < len1; i++) {
                if (str1[i] != str2[i]) {
                    return false;
                }
            }
            if (str2[len1] != '/') {
                return false;
            }
            return true;

        } else {
            return false;
        }
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        sort(folder.begin(), folder.end());
        int len  = (int)folder.size();
        int idx1 = 0;
        int idx2 = 1;
        vector<bool> vis(len, 0);
        while(idx2 < len) {
            bool flag = isStartWith(folder[idx1], folder[idx2]);
            cout<<folder[idx1]<<" "<<folder[idx2]<<" flag:"<<flag<<endl;
            if (isStartWith(folder[idx1], folder[idx2])) {
                idx2++;
                if (vis[idx1] == 0) {
                    vis[idx1] = 1;
                    res.push_back(folder[idx1]);
                }
            } else {
                idx1 = idx2;
                idx2++;
                if (vis[idx1] == 0) {
                    vis[idx1] = 1;
                    res.push_back(folder[idx1]);
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

