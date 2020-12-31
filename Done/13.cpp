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

const int N = 105;
const int DIR_X[] = {0, 0, 1, -1};
const int DIR_Y[] = {1, -1, 0, 0};

class Solution {
public:
    int n;
    int m;
    bool vis[N][N];
    int getSum(int val) {
        int sum = 0;
        while(val) {
            int tmp = val % 10;
            val /= 10;
            sum += tmp;
        }
        return sum;
    }
    bool check(int x, int y, int k) {
        if (x >= 0 && x < n && y >= 0 && y < m) {
            int sum = getSum(x) + getSum(y);
            if (sum <= k) {
                return true;
            }
        }
        return false;
    }
    int movingCount(int m, int n, int k) {
        this->n = m;
        this->m = n;
        memset(vis, 0, sizeof(vis));
        queue<PII> que;
        que.push(MP(0, 0));
        vis[0][0] = 1;

        int cnt = 0;
        while(!que.empty()) {
            PII top = que.front();
            que.pop();
            int x = top.first;
            int y = top.second;
            cnt++;
            for (int i = 0; i < 4; i++) {
                int nextX = x + DIR_X[i];
                int nextY = y + DIR_Y[i];
                if (check(nextX, nextY, k)) {
                    if (vis[nextX][nextY] == 0) {
                        vis[nextX][nextY] = 1;
                        que.push(MP(nextX, nextY));
                    }
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;
    cout<<s.movingCount(16, 8, 4)<<endl;
    return 0;
}

