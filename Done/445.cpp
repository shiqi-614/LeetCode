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


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    stack<int> getStack(ListNode* l1) {
        stack<int> s1;
        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        return s1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1 = getStack(l1);
        stack<int> s2 = getStack(l2);
        int carry = 0;
        ListNode* res = NULL;
        while(1) {
            int val = 0;
            if (!s1.empty()) {
                val += s1.top(); 
                s1.pop();
            }
            if (!s2.empty()) {
                val += s2.top();
                s2.pop();
            }
            ListNode* current = new ListNode((val + carry) % 10);
            carry = (val + carry) / 10;
            current->next = res;
            res = current;
        }
        return res;
    }
};

int main() {
    return 0;
}

