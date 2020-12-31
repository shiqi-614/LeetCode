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
int calc(int n , int m) {
    vector<int> data(n, 0);
    for (int i = 0; i < n; i++) data[i] = i;
    int nCnt = n - 1;
    int idx = 0;
    while(nCnt--) {
        int mCnt = 0;
        while(1) {
            if (data[idx] != -1) {
                mCnt++;
            }
            if (mCnt == m) break;
            idx = (idx + 1) % n;
//            cout<<idx<<" "<<n<<" mCtn:"<<mCnt<<endl;
        }
        data[idx] = -1;
//        cout<<"n cnt:"<<nCnt<<endl;
    }
    for (int i = 0; i < n; i++) if (data[i] != -1) {
        return data[i];
    }
    return -1;
}

int main() {
    for (int i = 3; i <= 20; i++) {
        for (int j = 2; j <= i * 2; j++) {
            int res = calc(i, j);
            cout<<res<<" ";
        }
        cout<<endl;
    }
    return 0;
}

