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
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> in(n, 0);
        vector<int> out(n, 0);
        int len = (int)leftChild.size();
        for (int i = 0; i < len; i++) {
            if (leftChild[i] != -1) {
                out[i]++;
                in[leftChild[i]]++;
            }
            if (rightChild[i] != -1) {
                out[i]++;
                in[rightChild[i]]++;
            }
        }

        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (in[i] == 0) {
                cnt++;
            }
            if (in[i] > 1) {
                return false;
            }
            if (out[i] > 2) {
                return false;
            }
        }
        if (cnt != 1) {
            return false;
        }
        return true;
    }
};

int main() {
    return 0;
}

