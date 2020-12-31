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
    void getMap(vector<int> &num, map<int, int>& H) {
        int len = (int)num.size();
        for (int i = 0; i < len; i++) {
            H[num[i]]++;
        }
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> H1, H2;
        getMap(nums1, H1);
        getMap(nums2, H2);

        map<int, int>::iterator it;
        vector<int> res;
        for (it = H1.begin(); it != H1.end(); it++) {
            int value = it->first;
            int count = it->second;
            int minCount = min(count, H2[value]);
            for (int i = 0; i < minCount; i++) {
                res.push_back(value);
            }
        }
        return res;
    }
};
int main()
{
    return 0;
}

