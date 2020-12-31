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

const int N = 33;
class Solution {
public:
    int mat[N][N];
    string res;
    void getData() {
        memset(mat, 0, sizeof(mat));
        mat[0][0] = 1;
        for(int j = 0; j < N; j++) {
            mat[j][j] = 1;
            for(int i = j+1; i < N; i++) {
                if(j == 0)
                    mat[i][j] = 1;
                else
                    mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
            } 
        }
        //for (int i = 0; i < N; i++) {
            //cout<<mat[N - 1][i]<<" ";
        //}cout<<endl;
    }
    string kthSmallestPath(vector<int>& destination, int k) {
        res = "";
        getData();
        int x = destination[1];
        int y = destination[0];
        int sum = x + y;

        for (int i = 0; i < sum; i++) {
            // choose 0
            int tmp = mat[x - 1 + y][y];
            if (tmp >= k) {
                res += 'H';
                x--;

            } else {
                res += 'V';
                k -= tmp;
                y--;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> data;
    data.push_back(2);
    data.push_back(3);
    cout<<s.kthSmallestPath(data, 1)<<endl;
    cout<<s.kthSmallestPath(data, 2)<<endl;
    cout<<s.kthSmallestPath(data, 3)<<endl;
    cout<<s.kthSmallestPath(data, 4)<<endl;
    cout<<s.kthSmallestPath(data, 5)<<endl;
    cout<<s.kthSmallestPath(data, 6)<<endl;
    cout<<s.kthSmallestPath(data, 7)<<endl;
    cout<<s.kthSmallestPath(data, 8)<<endl;
    cout<<s.kthSmallestPath(data, 9)<<endl;
    cout<<s.kthSmallestPath(data, 10)<<endl;
    return 0;
}

