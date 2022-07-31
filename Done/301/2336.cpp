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

class SmallestInfiniteSet {
public:
    set<int> removed;
    SmallestInfiniteSet() {
        removed.clear();
    }
    
    int popSmallest() {
        int res = 1;
        while(1) {
            if (removed.find(res) == removed.end()) {
                removed.insert(res);
                return res;
            }
            res++;
        }
    }
    
    void addBack(int num) {
        if (removed.find(num) != removed.end()) {
            removed.erase(num); 
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
int main()
{
    return 0;
}


