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


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

typedef long long LL;
typedef pair<int,int> PII;
#define PB push_back
#define MP make_pair

class Solution {
public:
    vector<int> data;
    vector<PII> pairs;
    void getData(ListNode* head) {
        ListNode* current = head;
        while(current) {
            data.PB(current -> val);
            current = current -> next;
        }
    }

    void removeInLink(ListNode* head) {
        int idx = 0;
        ListNode* current = head;
        ListNode* begin;
        for (int i = 0; i < (int)pairs.size(); i++) {
            int st = pairs[i].first;
            int ed = pairs[i].second;
            cout<<"st:"<<st<<" ed:"<<ed<<endl;
            while(idx <= ed) {
                if (idx == st) {
                    begin = current;
                }
                if (idx == ed) {
                    begin->next = current -> next;
                }
                current = current -> next;
                idx++;
            }
        }
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        data.clear();
        pairs.clear();

        data.PB(0);
        getData(head);
        ListNode newHead(0);
        newHead.next = head;

        int len = (int)data.size();
        vector<int> sum(len, 0);
        for (int i = 0; i < len; i++) {
            if (i == 0) sum [i] = data[i];
            else sum[i] = sum[i - 1] + data[i];
        }

        int st = 0;
        while(st < len) {
            bool find = false;
            for (int ed = len - 1; ed > st; ed--) {
                if (sum[ed] == sum[st]) {
                    pairs.PB(MP(st, ed));
                    st = ed + 1;
                    find = true;
                    break;
                }
            }
            if (!find) st++;
        }
        removeInLink(&newHead); 
        return newHead.next;
    }
};

int main() {
    return 0;
}

