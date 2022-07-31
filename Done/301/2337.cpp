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
    bool canChange(string start, string target) {
        int len = start.length();
        int idx1 = len - 1;
        int idx2 = len - 1;
        while(idx1 >= 0) {
            while (idx1>=0 && target[idx1] == '_') {
                idx1--;
            }
            if (target[idx1] == 'R') {
                while(idx2 >= 0 && start[idx2] == '_') {
                    idx2--;
                }
                if (idx2 >= 0 && start[idx2] == 'R' && idx2 <= idx1) {
                    idx2--;
                } else {
                    return false;
                }
            } else {
                while(idx2 >= 0 && start[idx2] == '_') {
                    idx2--;
                }
                if (idx2 >= 0 && start[idx2] == 'L' && idx2 >= idx1) {
                    idx2--;
                } else {
                    return false;
                }
            }
            idx1--;
        }
        cout<<idx2<<endl;
        while(idx2 >= 0) {
            if (start[idx2] != '_') {
                return false;
            }
            idx2--;
        }
        return true;
    }
};


int main()
{
    return 0;
}


