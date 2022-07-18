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


const int N = 1005;

class Solution {
public:
    int n;
    vector<vector<int>> adj;
    int score[N];
    bool vis[N];
    int in_timestamp[N];
    int out_timestamp[N];
    int timestamp;

    int dfs(int idx, int& timestamp, vector<int>& nums) {
        vis[idx] = 1;
        in_timestamp[idx]= ++timestamp;
        int len = (int)adj[idx].size();
        score[idx] = nums[idx];
        for (int i = 0;i < len; i++) {
            int y = adj[idx][i];
            if (vis[y] == 0) {
                score[idx] ^= dfs(y, timestamp, nums);
            }
        }
        out_timestamp[idx]=++timestamp;
        return score[idx];
    }

    bool isChild(int x1, int y1, int x2, int y2) {
        if (in_timestamp[y1] < in_timestamp[y2] && out_timestamp[y1] > out_timestamp[y2]) {
            return true;
        }
        return false;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        timestamp = 0;
        memset(vis, 0, sizeof(vis));
        memset(score, 0, sizeof(score));
        memset(in_timestamp, 0, sizeof(in_timestamp));
        memset(out_timestamp, 0, sizeof(out_timestamp));

        this->n = (int)nums.size();
        adj.resize(n, vector<int>());

        int len = (int)edges.size();
        for (int i = 0; i < len; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(0, timestamp, nums);
        int res = (1<<30);
        //for (int i = 0; i < n; i++) {
        //    cout<<score[i]<<" ";
        //}cout<<endl;

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int x1 = edges[i][0];
                int y1 = edges[i][1];
                int x2 = edges[j][0];
                int y2 = edges[j][1];

                if (in_timestamp[x1] > in_timestamp[y1]) {
                    swap(x1, y1);
                }
                if (in_timestamp[x2] > in_timestamp[y2]) {
                    swap(x2, y2);
                }

                int tot = score[0];
                int tmp1 = 0;
                int tmp2 = 0;
                int tmp3 = 0;
                if (isChild(x1, y1, x2, y2)) {
                    tmp1 = tot ^ score[y1];
                    tmp2 = score[y1] ^ score[y2];;
                    tmp3 = score[y2];
                    //cout<<"i:"<<i<<" j:"<<j<<" 1"<<endl;
                } else if (isChild(x2, y2, x1, y1)) {
                    tmp1 = tot ^ score[y2];
                    tmp2 = score[y1] ^ score[y2];;
                    tmp3 = score[y1];
                    //cout<<"i:"<<i<<" j:"<<j<<" 2"<<endl;

                } else {
                    tmp1 = tot ^ score[y1] ^ score[y2];
                    tmp2 = score[y1];
                    tmp3 = score[y2];
                    //cout<<"i:"<<i<<" j:"<<j<<" 3"<<endl;
                }

                int mx = max(tmp1, max(tmp2, tmp3));
                int mi = min(tmp1, min(tmp2, tmp3));
                //cout<<" tmp1:"<<tmp1<<" tmp2:"<<tmp2<<" tmp3:"<<tmp3<<" mx:"<<mx<<" mi:"<<mi<<endl;
                res = min(res, mx - mi);
            }
        }
        return res;
    }
};


int main()
{
    cout<<(5^13)<<endl;
    return 0;
}


