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

typedef long long LL;
typedef pair<int, int> PII;

const int N = 30;

class Solution {
public:
    int len;
    vector<int> getDiff(int a, int b, int c, int d, vector<vector<int>>& cnt)
    {
        cout << "diff:" << a << " " << b << " " << c << " " << d << endl;
        vector<int> diff(N, 0);
        vector<int> diff1(N, 0);
        vector<int> diff2(N, 0);
        for (int i = 0; i < N; i++) {
            diff1[i] = cnt[b][i] - (a - 1 >= 0 ? cnt[a - 1][i] : 0);
            diff2[i] = cnt[d][i] - (c - 1 >= 0 ? cnt[c - 1][i] : 0);
        }
        for (int i = 0; i < N; i++) {
            diff[i] = diff1[i] - diff2[i];
        }
        return diff;
    }

    bool checkSameCnt(vector<int>& diff1, vector<int>& diff2)
    {
        for (int i = 0; i < N; i++) {
            if (diff1[i] != diff2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkSwapCnt(vector<int>& diff, int len)
    {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += abs(diff[i]);
        }
        return sum == len;
    }

    bool checkCross(int a, int b, int c, int d, vector<vector<int>>& cnt)
    {
        cout << "checkCross:" << a << " " << b << " " << c << " " << d << endl;
        if (a < c) {
            vector<int> diff1 = getDiff(a, b, len - 1 - c + 1, len - 1 - a, cnt);
            vector<int> diff2 = getDiff(len - 1 - d, len - 1 - c, b + 1, d, cnt);
            if (checkSameCnt(diff1, diff2) && checkSwapCnt(diff1, b - c + 1)) {
                return true;
            }
            return false;
        } else {

            vector<int> diff1 = getDiff(a, b, len - 1 - b, len - 1 - d - 1, cnt);
            vector<int> diff2 = getDiff(len - 1 - d, len - 1 - c, c, a - 1, cnt);
            if (checkSameCnt(diff1, diff2) && checkSwapCnt(diff1, d - a + 1)) {
                return true;
            }
            return false;
        }
    }
    bool checkSum(int st, int ed, vector<int>& sum)
    {
        cout << "checkSum:" << st << " " << ed << endl;
        if (st > ed || st >= len / 2 || ed >= len / 2) {
            return true;
        }
        int tmp = sum[ed] - (st - 1 >= 0 ? sum[st - 1] : 0);
        return tmp == ed - st + 1;
    }
    bool checkCnt(int st, int ed, vector<vector<int>>& cnt)
    {
        if (st > ed) {
            return true;
        }
        int eed = len - 1 - st;
        int sst = len - 1 - ed;
        cout << "checkCnt:" << st << " " << ed << endl;
        cout << "next st:" << sst << " " << eed << endl;
        for (int i = 0; i < N; i++) {
            int tmp1 = cnt[ed][i] - (st - 1 >= 0 ? cnt[st - 1][i] : 0);
            int tmp2 = cnt[eed][i] - cnt[sst - 1][i];
            // cout << "cnt1: " << tmp1 << " " << tmp2 << endl;
            // cout << "cnt2:" << cnt[eed][i] << " " << cnt[sst - 1][i] << endl;
            if (tmp1 != tmp2) {
                return false;
            }
        }
        return true;
    }

    bool check(vector<int>& query, vector<int>& sum, vector<vector<int>>& cnt)
    {
        int a = query[0];
        int b = query[1];
        int c = query[2];
        int d = query[3];
        c = len - 1 - c;
        d = len - 1 - d;
        swap(c, d);
        cout << a << " " << b << " " << c << " " << d << endl;
        int actualLen = max(b, d) - min(a, c) + 1;
        int sumLen = (d - c + 1) + (b - a + 1);
        int maxLen = max(d - c + 1, b - a + 1);
        cout << "actual:" << actualLen << " sum:" << sumLen << " max:" << maxLen << endl;
        if (actualLen == maxLen) {
            cout << "case1" << endl;
            int st = min(a, c);
            int ed = max(b, d);
            return checkSum(0, st - 1, sum) && checkCnt(st, ed, cnt) && checkSum(ed + 1, len / 2 - 1, sum);
        } else if (actualLen < sumLen) {
            cout << "case2" << endl;
            return checkSum(0, min(a, c) - 1, sum)
                && checkSum(max(b, d) + 1, len / 2 - 1, sum)
                && checkCross(a, b, c, d, cnt);

        } else if (actualLen >= sumLen) {
            cout << "case3" << endl;
            return checkSum(0, min(a, c) - 1, sum)
                && checkSum(min(b, d) + 1, max(a, c) - 1, sum)
                && checkSum(max(b, d) + 1, len / 2 - 1, sum)
                && checkCnt(a, b, cnt)
                && checkCnt(c, d, cnt);
        }
        return false;
    }

    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries)
    {
        len = (int)s.length();
        vector<vector<int>> cnt(len, vector<int>(N, 0));
        vector<int> sum(len / 2, 0);
        for (int i = 0; i < len / 2; i++) {
            if (s[i] == s[len - 1 - i]) {
                sum[i]++;
            }
            if (i > 0) {
                sum[i] += sum[i - 1];
            }
            // cout << sum[i] << " ";
        }
        // cout << endl;

        for (int i = 0; i < len; i++) {
            int chr = s[i] - 'a';
            cnt[i][chr]++;
            for (int j = 0; j < N; j++) {
                if (i > 0) {
                    cnt[i][j] += cnt[i - 1][j];
                }
            }
        }
        // cout << "cnt" << endl;
        vector<bool> res;
        for (auto query : queries) {
            // cout << "query" << endl;
            res.push_back(check(query, sum, cnt));
        }
        return res;
    }
};

int main()
{
    // string tmp = "asuoeudxwa";
    // reverse(tmp.begin(), tmp.end());
    // cout << tmp << endl;
    return 0;
}
