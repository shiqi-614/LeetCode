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

const int MOD = 1e9 + 7;
const int N = 1e4 + 5;
const int M = 20;


class Solution {
public:
    int n;
    LL res;
    int C[N][M];

    void pre_calc() {
        memset(C, 0, sizeof(C));
        C[0][0] = 1;
        C[1][1] = 1;
        C[1][0] = 1;
        for (int i = 2; i < N; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= min(i, M - 1); j++) {
                C[i][j]  = (C[i-1][j] + C[i-1][j-1]) % MOD;
                // cout<<C[i][j] <<" ";
            }
            // cout<<endl;
        }
    }

    int calc_c(int tot, int choose) {
        return C[tot][choose];
    }
    int calc(vector<int>& data) {
        int len = (int)data.size();
        // cout<<"data: ";
        // for (int i = 0; i < len; i++) {
            // cout<<data[i]<<" ";
        // }cout<<endl;

        return calc_c(n - 1, len - 1);
    }
    void dfs(int value, int maxValue, vector<int>& data) {
        res = (res + calc(data)) % MOD;
        for (int i = 2; value * i <= maxValue && (int)data.size() < n; i++) {
            data.push_back(value * i);
            dfs(value * i, maxValue, data);
            data.pop_back();
        }
    }

    int idealArrays(int n, int maxValue) {
        pre_calc();
        res = 0;
        this->n = n;
        vector<int> data;
        for (int i = 1; i <= maxValue; i++) {
            data.push_back(i);
            dfs(i, maxValue, data);
            data.pop_back();
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.idealArrays(2, 5)<<endl;
    cout<<s.idealArrays(5, 3)<<endl;
    cout<<s.idealArrays(282, 297)<<endl;
    cout<<s.idealArrays(5878, 2900)<<endl;
    return 0;
}


