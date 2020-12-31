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

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> H;
        for (int i = 0; i < (int)employees.size(); i++) {
            H[employees[i]->id] = employees[i];
        }
        queue<int> que;
        que.push(id);

        int res = 0;
        while(!que.empty()) {
            int id = que.front();
            que.pop();

            Employee* employee = H[id];
            res += employee->importance;
            for (int i = 0; i < (int)employee->subordinates.size(); i++) {
                que.push(employee->subordinates[i]);
            }
        }
        return res;
    }
};
int main() {
    return 0;
}

