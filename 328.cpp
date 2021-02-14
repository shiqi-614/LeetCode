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

struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if (head == NULL) {
            return head;
        }
        ListNode* headNext = head->next;

        ListNode* odd = head;
        ListNode* even = odd->next;
        if (even == NULL) {
            return head;
        }

        while (1) {
            ListNode* current = even->next;
            if (current == NULL) {
                break;
            }
            odd->next = current;
            even->next = current->next;
            odd = current;
            even = current->next;
            if (even == NULL) {
                break;
            }
        }
        odd->next = headNext;
        return head;
    }
};

int main()
{
    return 0;
}
