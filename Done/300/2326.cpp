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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool inRange(int x, int y, int m, int n, vector<vector<int>> & data) {
        if (x >= 0 && y >= 0 && x < m && y < n && data[x][y] != -1) {
            return true;
        }
        return false;
    }

    void getNextPos(int &x, int &y, int dir, int m, int n, vector<vector<int>> &data) {
        while(1) {
            if (dir % 4 == 0) {
                if (inRange(x +1, y, m ,n, data)) {
                    x++;
                    return;
                } else {
                    dir++;
                } 
            } else if (dir % 4 == 1) {
                if (inRange(x, y + 1, m ,n, data)) {
                    y++;
                    return;
                } else {
                    dir++;
                } 
            } else if (dir % 4 == 2) {
                if (inRange(x - 1, y, m ,n, data)) {
                    x--;
                    return;
                } else {
                    dir++;
                } 
            } else {
                if (inRange(x, y - 1, m ,n, data)) {
                    x--;
                    return;
                } else {
                    dir++;
                } 

            }

        }
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));        
        if (head == NULL) {
            return res;
        }
        int dir = 0;
        int x = 0; 
        int y = 0;
        while (1) {
            res[x][y] = head->val;
            head = head->next;
            if (head == NULL) break;
            getNextPos(x, y, dir, m, n, res);
        }
        return res;
    }
};
int main()
{
    return 0;
}


