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

const char OPS[] = {'+', '-', '*', '/'};
#define EPS 1e-8

class Solution {
public:
    vector<char> ops;
    vector<int> nums;
    bool flag;
    vector<int> order;
    double calc(vector<double>& data, int idx) {
        double res = 0.0;
        if (ops[idx] == '+') {
            res = data[idx] + data[idx + 1];
            data[idx] = res;
            data[idx + 1] = res;
        } else if (ops[idx] == '-') {
            res = data[idx] - data[idx + 1];
            data[idx] = res;
            data[idx + 1] = res;
        } else if (ops[idx] == '*') {
            res = data[idx] * data[idx + 1];
            data[idx] = res;
            data[idx + 1] = res;
        } else {
            res = data[idx]*1.0 / data[idx + 1];
            data[idx] = res;
            data[idx + 1] = res;
        }
        return res;
    }
    double getRes() {
        vector<double> data;
        for (int i = 0; i < (int)nums.size(); i++) {
            data.PB(nums[i] * 1.0);
        }
        double res = 0.0;
        for (int i = 1; i <= (int)order.size(); i++) {
            for (int j = 0; j < (int)order.size(); j++) {
                if (i == order[j]) {
                    res = calc(data, j);
                }
            }
            if (i == 2 && order[1] == 1) {
                if (order[0] == 2) {
                    data[2] = data[0];
                } else if (order[2] == 2) {
                    data[1] = data[3];
                }
            }
            //cout<<"data:"<<endl; for (int j = 0; j < (int)data.size(); j++) cout<<data[j]<<" "; cout<<endl;
        }
        return res;
    }
    bool check() {
        sort(order.begin(), order.end());
        do {
            double res = getRes();
            //cout<<"order:"<<endl; for (int i = 0; i < (int)order.size(); i++) cout<<order[i]<<" "; cout<<endl;
            //cout<<"ops:"<<endl; for (int i = 0; i < (int)ops.size(); i++) cout<<ops[i]<<" "; cout<<endl;
            //cout<<"nums:"<<endl; for (int i = 0; i < (int)nums.size(); i++) cout<<nums[i]<<" "; cout<<endl;
            //cout<<"res:"<<res<<endl;
            //cout<<"\n"<<endl;
            if (abs(res - 24.0) < EPS) {
                return true;
            }
        } while(next_permutation(order.begin(), order.end()));
        return false;
    }
    void dfs(int idx) {
        if (idx == 3) {
            flag |= check();
        } else {
            for (int i = 0; i < 4; i++) {
                ops.PB(OPS[i]);
                dfs(idx + 1);
                ops.pop_back();
            }
        }

    }
    bool judgePoint24(vector<int>& nums) {
        this->nums = nums;
        order.PB(1);
        order.PB(2);
        order.PB(3);
        sort(this->nums.begin(), this->nums.end());
        do {
            dfs(0);
        } while(next_permutation(this->nums.begin(), this->nums.end()));
        return flag;
    }
};

int main() {
    cout<<EPS<<endl;
    Solution s;
    vector<int> data;
    data.PB(4);
    data.PB(1);
    //data.PB(8);
    //data.PB(7);
    data.PB(2);
    data.PB(3);
    cout<<s.judgePoint24(data)<<endl;
    return 0;
}

