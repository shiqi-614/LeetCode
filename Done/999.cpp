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

const int DIR_X[] = {0, 0, 1, -1};
const int DIR_Y[] = {1, -1, 0, 0};

class Solution {
public:
    int n;
    int m;
    bool judge(int x, int y) {
        if (0 <= x && x < n && 0 <= y && y < m) {
            return true;
        }
        return false;
    }
    int numRookCaptures(vector<vector<char> >& board) {
        this -> n = (int)board.size();
        this -> m = (int)board[0].size();
        int X = -1;
        int Y = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'R') {
                    X = i;
                    Y = j;
                }
            }
        }

        cout<<"x:"<<X<<" y:"<<Y<<endl;

        int cnt = 0;
        bool vis[4];
        int res = 0;
        memset(vis, 1, sizeof(vis));
        while(1) {
            cnt++;
            bool flag = false;
            for (int i = 0; i < 4; i++) if (vis[i]) {
                int x = X + DIR_X[i] * cnt;
                int y = Y + DIR_Y[i] * cnt;
                if (judge(x, y)) {
                    if (board[x][y] == 'p') {
                        res++;
                    } else if (board[x][y] == 'B') {
                        vis[i] = 0;
                    }
                    flag = true;
                }
            }
            if (flag == false) {
                break;
            }
        }
        return res;


    }
};

int main() {
    return 0;
}

