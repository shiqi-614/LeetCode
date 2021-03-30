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

const LL MOD = 1e9 + 7;

struct Node {
    LL price;
    LL amount;
    LL type;
    Node()
    {
    }
    Node(LL price, LL amount, LL type)
        : price(price)
        , amount(amount)
        , type(type)
    {
    }
    bool operator<(const Node& B) const
    {
        if (this->type == 0) {
            return this->price < B.price;
        } else {
            return this->price > B.price;
        }
    }
};
class Solution {
public:
    LL getNums(priority_queue<Node>& que)
    {
        LL res = 0;
        while (!que.empty()) {
            Node tmp = que.top();
            que.pop();
            cout << tmp.amount << endl;

            res += tmp.amount;
            res %= MOD;
        }
        return res;
    }
    int getNumberOfBacklogOrders(vector<vector<int>>& orders)
    {
        int len = (int)orders.size();
        LL res = 0;
        priority_queue<Node> buy;
        priority_queue<Node> sell;

        for (int i = 0; i < len; i++) {
            if (orders[i][2] == 0) {
                Node order = Node(orders[i][0], orders[i][1], orders[i][2]);
                while (!sell.empty()) {
                    Node tmp = sell.top();
                    if (tmp.price <= order.price) {
                        sell.pop();
                        if (tmp.amount > order.amount) {
                            tmp.amount -= order.amount;
                            order.amount = 0;
                            sell.push(tmp);
                            break;
                        } else {
                            order.amount -= tmp.amount;
                        }
                    } else {
                        break;
                    }
                }
                if (order.amount > 0) {
                    buy.push(order);
                }

            } else {
                Node order = Node(orders[i][0], orders[i][1], orders[i][2]);
                while (!buy.empty()) {
                    Node tmp = buy.top();
                    if (tmp.price >= order.price) {
                        buy.pop();
                        if (tmp.amount > order.amount) {
                            tmp.amount -= order.amount;
                            order.amount = 0;
                            buy.push(tmp);
                            break;
                        } else {
                            order.amount -= tmp.amount;
                        }
                    } else {
                        break;
                    }
                }
                if (order.amount > 0) {
                    sell.push(order);
                }
            }
        }
        res = (res + getNums(buy)) % MOD;
        res = (res + getNums(sell)) % MOD;

        return res;
    }
};

int main()
{
    priority_queue<Node> que;
    que.push(Node(1, 0, 1));
    que.push(Node(2, 0, 1));
    cout << que.top().price << endl;
    return 0;
}
