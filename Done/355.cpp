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

class Twitter {
public:
    vector<PII> twitters;
    map<int, set<int> > users;
    /** Initialize your data structure here. */
    Twitter() {
        twitters.clear();
        users.clear();

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        twitters.push_back(MP(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        int len = (int)twitters.size();
        vector<int> res;
        for (int i = len - 1; i >= 0 && (int)res.size() < 10; i--) {
            PII twitter = twitters[i];
            int user = twitter.first;
            int twitterId = twitter.second;
            if (user == userId) {
                res.PB(twitterId);
            } else if (users.find(userId) != users.end() && users[userId].find(user) != users[userId].end()) {
                res.PB(twitterId);
            }
        }
        return res;

    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (users.find(followerId) == users.end()) {
            users[followerId] = set<int>();
        }
        users[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (users.find(followerId) != users.end()) {
            users[followerId].erase(followeeId);
        }
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main() {
    return 0;
}

