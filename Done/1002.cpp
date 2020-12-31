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
    void merge(vector<int>& data1, vector<int>& data2) {
        for (int i = 0; i < 30; i++) {
            data1[i] = min(data1[i], data2[i]);
        }
    }
    vector<int> getData(string s) {
        vector<int> data(30, 0);
        for (int i = 0; i < (int)s.length(); i++) {
            data[s[i]-'a']++;
        }
        return data;
    }
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        int len = (int)A.size();
        if (len == 0) return res;
        vector<int> data = getData(A[0]);
        for (int i = 1; i < len; i++) {
            vector<int> tmp = getData(A[i]);
            merge(data, tmp);
        }
        
        for (int i = 0; i < 26; i++) {
            while(data[i] > 0) {
                string chr = "";
                chr += (i + 'a');
                res.push_back(chr);
                data[i]--;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}

