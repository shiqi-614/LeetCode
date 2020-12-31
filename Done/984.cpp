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
    string strWithout3a3b(int A, int B) {
        string res = "";
        while(A || B) {
            if (A > B) {
                int len = (int)res.length();
                if (len >= 2 && res[len - 1] == 'a' && res[len - 2] == 'a') {
                    res += 'b';
                    B--;
                } else {
                    res += 'a';
                    A--;
                }
            } else {
                int len = (int)res.length();
                if (len >= 2 && res[len - 1] == 'b' && res[len - 2] == 'b') {
                    res += 'a';
                    A--;
                } else {
                    res += 'b';
                    B--;
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

