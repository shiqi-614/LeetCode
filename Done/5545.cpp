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

const int N = 1005;

struct Node {
    int score;
    int age;
    Node(){}
    Node(int score, int age) : score(score), age(age) {}
    bool operator<(const Node& b) const{
        if (age != b.age) return age < b.age;
        return score < b.score;
    }
};
class Solution {
public:
    vector<int> scores;
    vector<int> ages;
    int dp[N];

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        this->scores = scores;
        this->ages = ages;
        int len = (int)scores.size();

        int res = 0;
        for (int i = 0; i < len; i++) res = max(res, scores[i]);

        vector<Node> data;
        for (int i = 0; i < len; i++) {
            data.push_back(Node(scores[i], ages[i]));
        }
        sort(data.begin(), data.end());
        for (int i = 0; i < len; i++) {
            cout<<data[i].score<<" "<<data[i].age<<endl;
        }

        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < len; i++) {
            dp[i] = data[i].score;
            for (int j = i - 1; j >= 0; j--) if (data[i].score >= data[j].score) {
                dp[i] = max(dp[i], dp[j] + data[i].score);
            } 
        }
        for (int i = 0; i < len; i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    return 0;
}

