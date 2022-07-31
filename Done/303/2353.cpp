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

struct Node {
    string food;
    string cuisine;
    int rating;
    Node() {}
    Node(string food, string cuisine, int rating) : food(food), cuisine(cuisine), rating(rating) {}
    bool operator<(const Node& b) const {
        if (rating != b.rating) {
            return rating < b.rating;
        } else {
            return food > b.food;
        }
    }
    void print() {
        cout<<"food:"<<food<<" cuisine:"<<cuisine<<" rating:"<<rating<<endl;
    }
};
class FoodRatings {
public:
    map<string, pair<string,int>> H;
    map<string, priority_queue<Node>> que;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int len = (int)foods.size();

        for (int i = 0;i < len; i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
            H[foods[i]] = make_pair(cuisine, rating);
            que[cuisine].push(Node(food, cuisine, rating));
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = H[food].first;
        H[food] = make_pair(cuisine, newRating);
        que[cuisine].push(Node(food, cuisine, newRating));
    }
    
    string highestRated(string cuisine) {

        while(!que[cuisine].empty()) {
            Node tmp = que[cuisine].top();
            if (tmp.rating == H[tmp.food].second) {
                cout<<"cuisine is "<<cuisine<<endl;
                tmp.print();
                return tmp.food;
            } else {
                que[cuisine].pop();
            }
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
int main()
{
    return 0;
}


