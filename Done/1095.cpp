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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

#define MID(st, ed) (st + ed) / 2
class Solution {
public:
    int binarySearchDown(int st, int ed, int target, MountainArray &mountainArr) {
        while(st < ed) {
            int mid = MID(st, ed);
            int midValue = mountainArr.get(mid);
            if (midValue == target) return mid;
            else if (target > midValue) {
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        if (st == ed && mountainArr.get(st) == target) return st;
        return -1;
    }
    int binarySearchUp(int st, int ed, int target, MountainArray &mountainArr) {
        while(st < ed) {
            int mid = MID(st, ed);
            int midValue = mountainArr.get(mid);
            if (midValue == target) return mid;
            else if (midValue < target) {
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        if (st == ed && mountainArr.get(st) == target) return st;
        return -1;
    }

    int search(int st, int ed, int target, MountainArray &mountainArr) {
        int mid = mountainArr.get(MID(st, ed));
        int midLft = mountainArr.get(MID(st, ed) - 1);
        int midRht = mountainArr.get(MID(st, ed) + 1);

        int res = -1;
        if (midLft < mid && mid > midRht) {
            res = binarySearchUp(st, MID(st, ed), target, mountainArr);
            if (res != -1) return res;
            res = binarySearchDown(MID(st, ed), ed, target, mountainArr);
        } else if (midLft < mid && mid < midRht) {
            if (target <= mid) {
                res = binarySearchUp(st, MID(st, ed), target, mountainArr);
            } else {
                res = search(MID(st, ed), ed, target, mountainArr);
            } 
        } else if (midLft > mid && mid > midRht) {
            res = search(st, MID(st, ed), target, mountainArr);
            if (res != -1) return res;
            if (target < mid) res = binarySearchDown(MID(st, ed), ed, target, mountainArr);
        }
        return res;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        return search(0, mountainArr.length() - 1, target, mountainArr);
    }
};

int main()
{
    return 0;
}

