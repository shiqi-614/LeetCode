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
    int myAtoi(string str) {
        string str1 = "";
        for (int i = 0; i < (int)str.length(); i++) {
            if (str[i] != ' ') str1 += str[i];
        }
        if(str1.length()==0) return 0;
        
        stringstream ss;
        ss<<str1;
        int dig;
        ss>>dig;
        return dig;
    }
};

int main() {
    return 0;
}

