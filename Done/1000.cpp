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

const int N = 35;
const int INF = (1<<28);
class Solution {
public:
    int dp[N][N][N];
    int sum[N];
    int orgK;
    int getSum(int st, int ed) {
        return sum[ed] - (st - 1 >= 0 ? sum[st - 1] : 0);
    }

    int dfs(int st, int ed, int K) {
//        cout<<st<<" "<<ed<<" "<<K<<endl;
        if (st == ed && K == 1) {
            return 0;
        } else if (ed - st + 1 < K) {
            return INF;
        } else {
            int &res = dp[st][ed][K];
            if (res != -1) return res;
            res = INF;
            if (K == 1) {
                res = dfs(st, ed, orgK);
            } else if (K > 1) {
                for (int i = st; i < ed; i++) {
                    if (K == orgK) {
                        res = min(res, dfs(st, i, 1) + dfs(i + 1, ed, K - 1) + getSum(st, ed));
                    } else {
                        res = min(res, dfs(st, i, 1) + dfs(i + 1, ed, K - 1));
                    }
                }
            }
//            if (res != INF) cout<<"st:"<<st<<" ed:"<<ed<<" K:"<<K<<" res:"<<res<<endl;
            return res;
        }
    }
    int mergeStones(vector<int>& stones, int K) {
        memset(dp, -1, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        this->orgK = K;
        int len = (int)stones.size();

        if (len == 1) return 0;

        for (int i = 0; i < len; i++) {
            sum[i] += stones[i];
            if (i - 1 >= 0) sum[i] += sum[i - 1];
        }
        //cout<<"sum:"<<sum[len - 1]<<endl;
        //for (int i = 0; i + K - 1 < len; i++) {
            //cout<<getSum(i, i + K - 1)<<" ";
        //}cout<<endl;

        int res = dfs(0, len - 1, K);
        if (res == INF) return -1;
        return res;
    }
};

int main()
{
    Solution s;
    //tmp.push_back(3);
    //tmp.push_back(2);
    //tmp.push_back(4);
    //tmp.push_back(1);

    //tmp.push_back(3);
    //tmp.push_back(5);
    //tmp.push_back(1);
    //tmp.push_back(2);
    //tmp.push_back(6);
    int data[] = {22,91,24,26,21,100,42,23,56,64,43,95,76,84,79,89};
    vector<int> tmp;
    for (int i = 0; i < (int)sizeof(data)/sizeof(int); i++) {
        tmp.push_back(data[i]);
    }
    cout<<s.mergeStones(tmp, 6)<<endl;
    return 0;
}

/* 
 *

[22,91,24,26,21,100,42,23,56,64,43,95,76,84,79,89]
 *
 *
 * */
