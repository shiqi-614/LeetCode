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
    int minChanges(vector<int>& nums, int k)
    {
        vector<int> xors;
        int len = (int)nums.size();
        for (int i = 0; i + k <= len; i++) {
            int tmp = 0;
            for (int j = 0; j < k; j++) {
                tmp = tmp ^ nums[i + j];
            }
            xors.push_back(tmp);
        }
        for (int i = 0; i < (int)xors.size(); i++) {
            cout << xors[i] << " ";
        }
        cout << endl;
        return 0;
    }
};

int main()
{
    int tmp[] = { 3, 4, 5, 2, 1, 7, 3, 4, 7 };
    vector<int> data;
    for (int i = 0; i < (int)sizeof(tmp) / sizeof(int); i++) {
        data.push_back(tmp[i]);
    }
    Solution s;
    s.minChanges(data, 3);
    return 0;
}
