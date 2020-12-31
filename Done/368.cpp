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
    int mx;
    int len;
    int pos;
    queue<int> que;
    map<int, vector<int> > adj;
    vector<int> nums;
    vector<int> dis;
    vector<bool> vis;
    map<int, int> H;
    map<int, int> pre;
    void build_adj() {

        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (H.find(nums[i]) == H.end()) {
                H.insert(make_pair(nums[i], cnt++));
            }
        }

        vis.resize(cnt, 0);
        dis.resize(cnt, -1);
        for (int i = 0; i < len; i++) {
            bool flag = false;
            for (int j = 1; j * j <= nums[i]; j++) {
                if (nums[i] % j == 0 &&  j != nums[i]) {
                    if (H.find(j) != H.end()) {
                        adj[H[j]].push_back(nums[i]);
//                        cout<<"edge:"<<j<<" "<<nums[i]<<endl;
                        flag = true;
                    }
                    if (H.find(nums[i]/j) != H.end() && nums[i] / j != j && nums[i] / j != nums[i]) {
                        adj[H[nums[i]/j]].push_back(nums[i]);
                        flag = true;
//                        cout<<"edge:"<<nums[i]/j<<" "<<nums[i]<<endl;
                    }

                }
            }
            if (flag == false) {
                que.push(nums[i]);
//                cout<<"begin:"<<nums[i]<<endl;
                vis[H[nums[i]]] = 1;
                dis[H[nums[i]]] = 0;
            }
        }

    }

    void spfa() {
        
        while(!que.empty()) {
            int from = que.front(); que.pop();
            int hashFrom = H[from];
            vis[hashFrom] = 0;
            if (dis[hashFrom] > mx) {
                mx = dis[hashFrom];
                pos = from;
            }
            for (int i = 0; i < (int)adj[hashFrom].size(); i++) {
                int to = adj[hashFrom][i];
                int hashTo = H[to];
//                cout<<"from:"<<from<<" to:"<<to<<endl;
                if (dis[hashTo] < dis[hashFrom] + 1) {
                    dis[hashTo] = dis[hashFrom] + 1;
                    pre[to] = from;
                    if (dis[hashTo] > mx) {
                        mx = dis[hashTo];
                        pos = to;
//                        cout<<"dis:"<<dis[hashTo]<<" to:"<<to<<" from:"<<from<<endl;
                    }
                    if (vis[hashTo] == 0) {
                        vis[hashTo] = 1;
                        que.push(to);
//                        cout<<"insert que:"<<to<<endl;
                    }
                }
            }
        }
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        this->nums = nums;
        this->len = (int)nums.size();
        this->adj.clear();
        this->H.clear();
        this->pre.clear();
        this->mx = -1;
        build_adj();
        spfa();

//        cout<<"mx:"<<mx<<" pos:"<<pos<<endl;
        vector<int> res;
        res.push_back(pos);
        while(1) {
            if (pre.find(pos) == pre.end()) {
                break;
            }
            pos = pre[pos];
            res.push_back(pos);

        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    int a[] = {2,3,8,9,27};
//    int a[] = {1,2,4,8};
    vector<int> data(a, a + sizeof(a) / sizeof(int));
    vector<int> res = s.largestDivisibleSubset(data);
    for (int i = 0; i < (int)res.size(); i++) {
        cout<<res[i] <<" ";
    }
    cout<<endl;
    return 0;
}

