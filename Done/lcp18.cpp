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

const LL MOD = 1000000007;

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());

        int len1 = (int)staple.size();
        int len2 = (int)drinks.size();
        if (len1 == 0 || len2 == 0) return 0;
        if (drinks[0] + staple[0] > x) return 0;
        
        int idx = 0;
        LL res = 0;
        while(idx + 1 < len2 && staple[0] + drinks[idx + 1] <= x) idx++;
        for (int i = 0; i < len1; i++) {
            cout<<staple[i] + drinks[idx]<<" x:"<<endl;
            while(idx >= 0 && staple[i] + drinks[idx] > x) idx--;
            if (staple[i] + drinks[idx] <= x) {
                cout<<"i:"<<i<<" idx:"<<idx<<endl;
                res = (res + idx + 1) % MOD;

            }
        }
        return res;
    }
};

int main()
{
    return 0;
}

