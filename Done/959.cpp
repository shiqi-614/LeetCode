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
const int M = N * N * 4;
class Solution {
public:
    int smallGrid[N][N][4];
    int fa[M];
    void unin(int x, int y) {
//        cout<<"unin:"<<x<<" y:"<<y<<endl;
        if (findFa(x) != findFa(y)) {
            fa[findFa(x)] = findFa(y);
//            cout<<"fax:"<<findFa(x)<<" fay:"<<findFa(y)<<endl;
        }
    }

    int findFa(int x) {
        if (fa[x] != x) return fa[x] = findFa(fa[x]);
        return fa[x];
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = (int)grid.size();
        if (n == 0) return 0;
        int m = (int)grid[0].length();
        int cnt = 0;
        for (int i = 0;i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    smallGrid[i][j][k] = cnt++;
                }
            }
        }
        for (int i = 0; i < M; i++) {
            fa[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '\\') {
                    unin(smallGrid[i][j][0], smallGrid[i][j][1]);
                    unin(smallGrid[i][j][2], smallGrid[i][j][3]);
                } else if (grid[i][j] == '/') {
                    unin(smallGrid[i][j][0], smallGrid[i][j][3]);
                    unin(smallGrid[i][j][2], smallGrid[i][j][1]);
                } else {

                    unin(smallGrid[i][j][0], smallGrid[i][j][1]);
                    unin(smallGrid[i][j][1], smallGrid[i][j][2]);
                    unin(smallGrid[i][j][2], smallGrid[i][j][3]);
                }

                if (i - 1 >= 0) {
                    unin(smallGrid[i][j][0], smallGrid[i - 1][j][2]);
                }
                if (i + 1 < n) {
                    unin(smallGrid[i][j][2], smallGrid[i + 1][j][0]);
                }
                if (j - 1 >= 0) {
                    unin(smallGrid[i][j][3], smallGrid[i][j - 1][1]);
                }
                if (j + 1 < m) {
                    unin(smallGrid[i][j][1], smallGrid[i][j + 1][3]);
                }

            }
        }

        set<int> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    res.insert(findFa(smallGrid[i][j][k]));
                }
            }
        }
        return (int)res.size();
    }
};
int main()
{
    Solution s;
    vector<string> data;
    data.push_back(" /");
    data.push_back("/ ");
    cout<<s.regionsBySlashes(data)<<endl;
    return 0;
}

