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
    int n;
    int res;
    void dfs(vector<int>& neg, int negIdx, vector<int>& pos, int sum, int dep) {
        // cout<<"sum:"<<sum<<" dep:"<<dep<<endl;
        // cout<<"neg:"<<endl;
        // for (int i = 0; i < (int)neg.size(); i++) {
            // cout<<neg[i]<<" ";
        // }cout<<endl;
        // cout<<"pos:"<<endl;
        // for (int i = 0; i < (int)pos.size(); i++) {
            // cout<<pos[i]<<" ";
        // }cout<<endl;

        if (sum == 0) {
            res = min(res, dep);
            return;
        }
        if (dep > res) {
            return;
        }

        int len = (int)pos.size();
        for (int i = 0; i < len; i++) if (pos[i] > 0) {
            int tmp = pos[i];
            if (pos[i] == -neg[negIdx]) {
                // cout<<"equal"<<endl;
                pos[i] = 0;
                dfs(neg, negIdx + 1, pos, sum - tmp, dep + 1);
                pos[i] = tmp;
            } else if (pos[i] < -neg[negIdx]) {
                // cout<<"small"<<endl;
                pos[i] = 0;
                neg[negIdx] += tmp;
                dfs(neg, negIdx, pos, sum - tmp, dep + 1);
                pos[i] = tmp;
                neg[negIdx] -= tmp;
            } else {
                // cout<<"big"<<endl;
                pos[i] += neg[negIdx];
                dfs(neg, negIdx + 1, pos, sum + neg[negIdx], dep + 1);
                pos[i] -= neg[negIdx];
            }
        }
    }

    int minTransfers(vector<vector<int>>& transactions) {
        this->n = (int)transactions.size();
        res = n;
        map<int, int> data;
        for (int i = 0; i < n; i++) {
            int x = transactions[i][0];
            int y = transactions[i][1];
            int z = transactions[i][2];
            data[x] -= z;
            data[y] += z;
        }
        vector<int> neg;
        vector<int> pos;
        int sum = 0;
        for (map<int, int>::iterator it = data.begin(); it != data.end(); it++) {
            if (it->second < 0) {
                neg.push_back(it->second);
            } else if (it->second > 0) {
                pos.push_back(it->second);
                sum += it->second;
            }
        }
        
        dfs(neg, 0, pos, sum, 0);
        return res;
    }
};
int main()
{
    freopen("465.in", "r", stdin);
    int n;
    int m;
    scanf("%d\n", &n);
    for (int i = 0;i < n; i++) {
        scanf("%d ", &m);
        vector<vector<int>> data;
        for (int j = 0; j < m; j++) {
            int a, b,c;
            if (j != m - 1) {
                scanf("[%d,%d,%d],", &a, &b, &c);
            } else {
                scanf("[%d,%d,%d]\n", &a, &b, &c);
            }

            vector<int> tmp;
            tmp.push_back(a);
            tmp.push_back(b);
            tmp.push_back(c);
            data.push_back(tmp);
        }
        Solution s;
        cout<<s.minTransfers(data)<<endl;

    }
    return 0;
}


