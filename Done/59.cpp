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

class MaxQueue {
public:
    stack<int> dp;
    stack<int> org;
    stack<int> backUp;
    int backUpMx;
        
    MaxQueue() {

    }
    
    int max_value() {
        int mx = -1;
        if (!dp.empty()) {
            mx = dp.top();
        }
        if (!backUp.empty()) {
            mx = max(mx, backUpMx);
        }
        return mx;
    }
    
    void push_back(int value) {
        if (backUp.empty()) {
            backUpMx = value;
        } else {
            backUpMx = max(backUpMx, value);
        }
        backUp.push(value);
    }
    
    int pop_front() {
        if (org.empty()) {
            while(!backUp.empty()) {
                int value = backUp.top();
                backUp.pop();
                org.push(value);
                if (dp.empty()) {
                    dp.push(value);
                } else {
                    int mx = max(value, dp.top());
                    dp.push(mx);
                }
            }
        } 
        if (!org.empty()) {
            int top = org.top();
            org.pop();
            dp.pop();
            return top;
        } else {
            return -1;
        }

    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main() {
    return 0;
}

