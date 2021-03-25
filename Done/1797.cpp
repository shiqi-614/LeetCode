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

class AuthenticationManager {
public:
    int timeToLive;
    map<string, int> H;
    AuthenticationManager(int timeToLive)
    {
        H.clear();
        this->timeToLive = timeToLive;
    }

    void generate(string tokenId, int currentTime)
    {
        if (H.find(tokenId) == H.end()) {
            H.insert(make_pair(tokenId, currentTime));
        } else {
            H[tokenId] = currentTime;
        }
    }

    void renew(string tokenId, int currentTime)
    {
        if (H.find(tokenId) != H.end()) {
            if (H[tokenId] + timeToLive > currentTime) {
                H[tokenId] = currentTime;
            }
        }
    }

    int countUnexpiredTokens(int currentTime)
    {
        int cnt = 0;
        for (auto [key, val] : H) {
            if (val + timeToLive > currentTime) {
                cnt++;
            }
        }
        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */

int main()
{
    return 0;
}
