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

const int N = 1e5;
const int M = 26;

class Solution {
public:
    int in[N];
    int out[N];
    int cnt[M];
    bool check(int k, int tot)
    {
        int sum = 0;
        for (int i = 0; i < M; i++) {
            sum += cnt[i];
            if (cnt[i] > 0 && cnt[i] != k) {
                return false;
            }
        }
        return tot == sum;
    }
    int countCompleteSubstrings(string word, int k)
    {
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        int len = (int)word.size();
        for (int i = 0; i < len - 1; i++) {
            if (abs(word[i] - word[i + 1]) > 2) {
                in[i + 1]++;
                out[i]--;
            }
            cout << in[i] << " " << out[i] << endl;
        }
        int res = 0;
        for (int j = k; j <= M * k && j <= len; j += k) {
            cout << "j:" << j << endl;
            memset(cnt, 0, sizeof(cnt));
            int sum = 0;
            for (int i = 0; i < len; i++) {
                cnt[word[i] - 'a']++;
                sum += in[i];
                if (i - j >= 0) {
                    cnt[word[i - j] - 'a']--;
                    sum -= out[i - j];
                }
                if (check(k, j) && sum == 0) {
                    res++;
                    cout << "j:" << j << " i:" << i << endl;
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
