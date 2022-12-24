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
    int similarPairs(vector<string>& words) {
        int len = (int)words.size();
        for (int i = 0; i < len; i++) {
            sort(words[i].begin(), words[i].end());
            words[i].erase(unique(words[i].begin(), words[i].end()), words[i].end());
        }        
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (words[i] == words[j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    return 0;
}


