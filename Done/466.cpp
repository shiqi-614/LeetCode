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
const int N = 205;
class Solution {
public:
    int visCnt[N];
    int visIdx[N];
    int nextStepCnt[N];
    int len1;
    int len2;
    int getNextPos(string s1, string s2) {
        for (int i = 0; i < len1; i++) {
            int idx1 = 0;
            int idx2 = 0;
            int cnt = 0;
            while (idx2 < len2) {
                if (s1[(i + idx1) % len1] == s2[idx2]) {
                    idx1++; idx2++;
                    cnt = 0;
                } else {
                    idx1++;
                }
                cnt++;
                if (cnt > len1) {
                    return -1;
                }
//                cout<<"idx1:"<<idx1<<" idx2:"<<idx2<<" cnt:"<<cnt<<endl;
            }
            nextStepCnt[i] = idx1;
        }
//        cout<<"next step:"; for (int i = 0; i < len1; i++) cout<<nextStepCnt[i]<<" "; cout<<endl;
        return 0;
    }

    int getMaxCnt(int totalLen) {
        int idx = 0;
        int cnt = 0;
        memset(visCnt, -1, sizeof(visCnt));
        memset(visIdx, -1, sizeof(visIdx));
        while(1) {
            if (visCnt[idx % len1] == -1) {
                visCnt[idx % len1] = cnt;
                visIdx[idx % len1] = idx;
            } else {
                int idxGap = idx - visIdx[idx % len1]; 
                int cntGap = cnt - visCnt[idx % len1];
                int cycleSize = (totalLen - 1 - idx) / idxGap;
                if (cycleSize > 0) {
                    cnt += cntGap * cycleSize;
                    idx += idxGap * cycleSize;
                }
            }
            idx += nextStepCnt[idx % len1];
            if (idx <= totalLen) {
                cnt++; 
            } else {
                break;
            }
        }
        return cnt;
    }

    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        memset(nextStepCnt, 0, sizeof(nextStepCnt));
        this->len1 = (int)s1.length();
        this->len2 = (int)s2.length();
        if (len1 == 0 || len2 == 0) return 0;
        if (getNextPos(s1, s2) == -1) return 0;
        int n = getMaxCnt(len1 * n1);
        cout<<"max cnt:"<<n<<endl;
        return n / n2;
    }
};

int main()
{
    Solution s;
    cout<<s.getMaxRepetitions("acb", 4, "ab", 2)<<endl;
    cout<<s.getMaxRepetitions("aaa", 3, "aa", 1)<<endl;
    cout<<s.getMaxRepetitions("baba", 11, "baab", 1)<<endl;
    return 0;
}

