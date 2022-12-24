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

const int N = 1e5 + 5;

class Solution {
public:
    bool isPrime(int n) {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int smallestValue(int n) {
        vector<int> prime;
        for (int i = 2; i < N; i++) {
            if (isPrime(i)) {
                prime.push_back(i);
            }
        }

        int len = (int)prime.size();
        int res = 1e9 + 10;
        while (1) {
            int sum = 0;
            for (int i = 0; i < len; i++) {
                while(n >= prime[i] && n % prime[i] == 0) {
                    n /= prime[i];
                    sum += prime[i];
                    cout<<prime[i]<<" ";
                }
            }
            cout<<endl;
            cout<<"sum:"<<sum<<endl;
            if (res == sum) break;
            res = min(res, sum);
            n = sum;

        }
        return res;
    }
};

int main()
{
    Solution s;
    // cout<<s.smallestValue(15)<<endl;
    // cout<<s.smallestValue(4)<<endl;
    cout<<s.smallestValue(99951)<<endl;
    return 0;
}


