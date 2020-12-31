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

class Solution {
public:
    string toBinaryString(int value) {
        string res = "";
        for (int i = 0; i < 8; i++) {
            if ((1<<i) & value) {
                res += "1";
            } else {
                res += "0";
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool validUtf8(vector<int>& data) {
        vector<string> binaryData;
        for (int i = 0; i < (int)data.size(); i++) {
            binaryData.push_back(toBinaryString(data[i]));
        }
        for (int i = 0; i < (int)data.size(); i++) {
            cout<<binaryData[i]<<endl;
        }
        
        int idx = 0;
        while(idx < (int)data.size()) {
            string value = binaryData[idx];
            int cnt = 0;
            for (int i = 0; i < (int)value.length(); i++) {
                if (value[i] == '1') {
                    cnt++;
                } else {
                    break;
                }
            }
            if (cnt == 1) {
                return false;
            }

            if (cnt == 0) {
                idx++;
            } else {
                if (idx + cnt > (int)data.size()) {
                    return false;
                }
                for (int i = 1; i < cnt; i++) {
                    if (binaryData[idx + i][0] == '1' && binaryData[idx + i][1] == '0') {
                        continue;
                    } else {
                        return false;
                    }
                }
                idx += cnt;
            }
        }
        return true;
    }
};

int main() {
    int a[] = {145};
    vector<int> data(a, a + sizeof(a) / sizeof(int));

    Solution s;
    cout<<s.validUtf8(data)<<endl;
    return 0;

}

