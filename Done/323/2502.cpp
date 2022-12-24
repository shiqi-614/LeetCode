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

// [null,0,1,2,1,0,0,0,0,-1,0]
// [null,0,1,2,1,3,1,6,3,-1,0]
// [null,0,12,-1,-1,12,0,0,-1,-1,-1,0,0,0,28,0,0,0,0,12,0,0,-1,0,-1,-1,0,0,0,-1,-1,-1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,0,12,0,0]
// [null,0,12,-1,-1,12,0,0,-1,-1,-1,0,0,0,28,0,0,0,0,12,0,0,-1,0,-1,-1,0,0,0,-1,-1,-1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,0,12,0,0];d
struct Node {
    int st;
    int ed;
    int id;
    Node() {}
    Node(int st, int ed, int id) : st(st), ed(ed), id(id) {}
    bool operator<(const Node& node) const {
        return st > node.st;
    }
    void print() {
        cout<<"st:"<<st<<" ed:"<<ed<<" id:"<<id<<endl;
    }
};

class Allocator {
public:
    priority_queue<Node> que;
    int n;
    int remain;
    Allocator(int n) {
        this->n = n;
        this->remain = n;
        while(que.size() > 0) {
            que.pop();
        }
        que.push(Node(n, n+1, 1e3 + 1));
    }
    
    int allocate(int size, int mID) {
        // cout<<"allocate:"<<size<<" "<<mID<<endl;
        if (size > remain) {
            return -1;
        }

        priority_queue<Node> tmp;
        int now = 0;
        while(que.size() > 0) {
            Node top = que.top(); que.pop();
            // top.print();
            tmp.push(top);
            if (top.st - now >= size) {
                // cout<<"insert:"<<now<<" "<<now + size - 1<<" "<<mID<<endl;
                que.push(Node(now, now + size -1, mID));
                this->remain -= size;
                break;
            } else {
                now = top.ed + 1;
            }
        }
        while(tmp.size() > 0) {
            Node top = tmp.top(); tmp.pop();
            que.push(top);
        }
        // cout<<"now:"<<now<<" remain:"<<this->remain<<endl;
        if (now >= n) return -1;
        return now;
    }
    
    int free(int mID) {
        // cout<<"free:"<<mID<<endl;
        int res = 0;
        priority_queue<Node> tmp;
        while(que.size() > 0) {
            Node top = que.top(); que.pop();
            if (top.id != mID) {
                tmp.push(top);
            } else {
                int size = top.ed - top.st + 1;
                res += size;
                this->remain += size;
            }
        }
        while(tmp.size() > 0) {
            Node top = tmp.top(); tmp.pop();
            que.push(top);
        }
        return res;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */

int main()
{
    return 0;
}


