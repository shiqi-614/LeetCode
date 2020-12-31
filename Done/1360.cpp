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

int MONTHS[] = {0, 31,28,31,30,31,30,31,31,30,31,30,31}; 

class Solution {
public:
    bool isRunNian(int year) {
        return (year%400==0)||(year%4==0&&year%100!=0);
    }
    int getYearDays(int year) {
        int res = 0;
        for (int i = 1970; i < year; i++) {
            if (isRunNian(i)) {
                res += 366;
            } else {
                res += 365;
            }
        }
        return res;
    }

    int toInt(string date) {
        int res = 0;
        for (int i = 0; i < (int)date.length(); i++) {
            res = res * 10 + (date[i] - '0');
        }
        return res;
    }
    int getMonthDay(int month, int year) {
        int res = 0;
        for (int i = 1; i < month; i++) {
            if (i == 2 && isRunNian(year)) {
                res += 29;
            } else {
                res += MONTHS[i];
            }
        }
        return res;
    }

    int getDelta(string date) {
        int year = toInt(date.substr(0, 4));
        int month = toInt(date.substr(5, 2));
        int day = toInt(date.substr(8, 2));

        return getYearDays(year) + getMonthDay(month, day) + day;
    }
    int daysBetweenDates(string date1, string date2) {
        int day1 = getDelta(date1);
        int day2 = getDelta(date2);
        return abs(day1 - day2);
    }
};

int main() {
    return 0;
}

