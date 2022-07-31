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

const int N = 100;

class Solution {
public:
    map<int, set<int>> H;
    int getNum(int num) {
        int cnt = 0;
        while(num) {
            if (num%2) cnt++;
            num/=2;
        }
        return cnt;
    }
    long long countExcellentPairs(vector<int>& nums, int k) {
        int cnt[N+5];
        memset(cnt, 0, sizeof(cnt));
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            H[getNum(nums[i])].insert(nums[i]);
        }

        for (map<int, set<int>>::iterator it = H.begin(); it != H.end(); it++) {
            cnt[it->first]=it->second.size();
        }


        LL res = 0;
        for (int i = 0; i < N; i++) {
            if (k - i > i) {
                for (int j = k - i; j < N; j++) {
                    // cout<<"1:"<<cnt[i] * cnt[j] * 1LL<<endl;
                    res += cnt[i] * cnt[j] * 2LL;
                }

            } else {
                res += cnt[i];
                // cout<<"2:"<<cnt[i]<<endl;
                for (int j = i + 1; j < N; j++) {
                    res += cnt[i] * cnt[j] * 2LL;
                    // cout<<"2:"<<cnt[i]*cnt[j] * 2LL<<endl;
                }
            }         
        }
        return res;
    }
};

int main()
{
    return 0;
}


