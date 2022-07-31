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

struct Node {
    string value;
    int index;
    Node(){ }
    Node(string value, int index) : value(value), index(index) {}
    bool operator<(const Node& b) const {
        if (value != b.value) {
            return value < b.value;
        }
        return index < b.index;
    }
    void print() {
        cout<<"value:"<<value<<" index:"<<index<<endl;
    }
}; 

class Solution {
public:
    int dfs(vector<string>& nums, vector<Node>& data, int k, int trim) {

        // cout<<"K:"<<k<<" trim:"<<trim<<" data size"<<data.size()<<endl;
        if (data.size() == 1 || trim == 0) {
            if (data.size() == 1) {
                return data[0].index;
            } else {
                return data[k].index;
            }
        } else {
            int len = (int)data.size();
            for (int i = 0; i < len; i++) {
                int len = (int)nums[data[i].index].length();
                data[i].value += nums[data[i].index][len-trim];
            }
            sort(data.begin(), data.end());
            // for (int i = 0; i < len; i++ ) {
                // data[i].print();
            // }
            vector<Node> sub;
            // cout<<"k:"<<k<<" ";
            // data[k].print();
            int kk = k;
            for (int i = 0; i < len; i++) {
                if (data[i].value < data[k].value) {
                    kk--;
                } else if (data[i].value == data[k].value) {
                    // cout<<"push:";
                    // data[i].print();
                    sub.push_back(data[i]);
                }
            }
            return dfs(nums, sub, kk, trim - 1);
        }
    }

    int getRes(vector<string>& nums, int k, int trim) {
        int len = (int)nums.size();
        vector<Node> data;
        for (int i = 0; i < len; i++) {
            data.push_back(Node("", i));
        }
        return dfs(nums, data, k, trim);
    }

    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int len = (int)queries.size();
        vector<int> res;
        for (int i = 0; i < len; i++) {
            // cout<<"query:"<<i<<endl;
            int k = queries[i][0];
            int trim = queries[i][1];
            int tmp = getRes(nums, k - 1, trim);
            res.push_back(tmp);
        }
        return res;
    }
};
int main()
{
    Solution s;

    return 0;
}


