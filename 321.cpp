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
    int pos;
    int val;
    Node() { }
    Node(int pos, int val)
        : pos(pos)
        , val(val)
    {
    }
    bool operator<(const Node& B) const
    {
        return val < B.val;
    }
};

bool sortByPos(const Node& a, const Node& b)
{
    return a.pos < b.pos;
}
void printVector(vector<Node>& data)
{

    for (int i = 0; i < (int)data.size(); i++) {
        cout << data[i].val << " ";
    }
    cout << endl;
}
void print(vector<Node>& order1, vector<Node>& order2, vector<int>& res)
{
    cout << "order1:" << endl;
    printVector(order1);
    cout << "order2:" << endl;
    printVector(order2);
    cout << "res::" << endl;
    for (int i = 0; i < (int)res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}
class Solution {
public:
    int len1;
    int len2;
    vector<int> merge(vector<Node>& order1, vector<Node>& order2, int K)
    {
        int idx1 = 0;
        int idx2 = 0;
        vector<int> res;
        while (1) {
            if (idx1 >= (int)order1.size() && idx2 >= (int)order2.size()) {
                break;
            }
            if (K <= 0) {
                break;
            }

            if (idx1 < (int)order1.size() && idx2 < (int)order2.size()) {
                if (order1[idx1].val > order2[idx2].val) {
                    res.push_back(order1[idx1].val);
                    idx1++;
                    K--;
                } else if (order1[idx1].val < order2[idx2].val) {
                    res.push_back(order2[idx2].val);
                    idx2++;
                    K--;
                } else {
                    if (compareUntilDifference(order1, order2, idx1, idx2)) {
                        res.push_back(order1[idx1].val);
                        idx1++;
                        K--;
                    } else {
                        res.push_back(order2[idx2].val);
                        idx2++;
                        K--;
                    }
                }
            } else if (idx1 < (int)order1.size()) {
                res.push_back(order1[idx1].val);
                idx1++;
                K--;
            } else {
                res.push_back(order2[idx2].val);
                idx2++;
                K--;
            }
        }
        return res;
    }

    string getStr(vector<int>& data)
    {
        string res = "";
        for (int i = 0; i < (int)data.size(); i++) {
            res += (data[i] + '0');
        }
        return res;
    }
    bool compareUntilDifference(vector<Node>& order1, vector<Node>& order2, int idx1, int idx2)
    {
        while (idx1 < (int)order1.size()
            && idx2 < (int)order2.size()
            && order1[idx1].val == order2[idx2].val) {
            idx1++;
            idx2++;
        }

        if (idx1 >= (int)order1.size())
            return false;
        if (idx2 >= (int)order2.size())
            return true;
        return order1[idx1].val > order2[idx2].val;
    }

    bool getList(vector<Node>& order, vector<int>& nums, int remain, vector<Node>& list1)
    {
        priority_queue<Node> que;
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int ed = order[i].pos - 1;
            int st = getSt(order, i - 1);
            list1.push_back(order[i]);

            for (int j = ed; j >= st; j--) {
                que.push(Node(j, nums[j]));
            }
            while (!que.empty() && remain) {
                list1.push_back(que.top());
                que.pop();
                remain--;
            }
        }
        sort(list1.begin(), list1.end(), sortByPos);
        if (remain == 0)
            return true;
        return false;
    }

    int getSt(vector<Node>& order, int idx)
    {
        if (idx < 0)
            return 0;
        else
            return order[idx].pos + 1;
    }

    vector<Node> getMaxSeq(int lft, int rht, vector<int>& nums, int cnt)
    {
        //cout << "get max seq:" << lft << " rht:" << rht << " cnt:" << cnt << endl;
        int remain = cnt;
        vector<Node> data;
        int len = (int)nums.size();
        if (len == 0)
            return data;
        vector<int> pos(len, -1);
        int mx = -1;
        int mxPos = -1;
        for (int i = rht; i >= lft; i--) {
            if (mx <= nums[i]) {
                mx = nums[i];
                mxPos = i;
            }
            pos[i] = mxPos;
        }
        int idx = pos[lft];
        while (idx <= rht && cnt) {
            data.push_back(Node(idx, nums[idx]));
            if (idx + 1 <= rht) {
                idx = pos[idx + 1];
            } else {
                break;
            }
            cnt--;
            //cout << "idx:" << idx << " val:" << nums[idx] << endl;
        }
        //cout << "lft:" << lft << " rht:" << rht << " remain:" << remain << " Max Seq:" << endl;
        //for (int i = 0; i < (int)data.size(); i++)
        //cout << data[i].val << " ";
        //cout << endl;
        return data;
    }

    vector<Node> getSeq(int lft, int rht, vector<int>& nums, int cnt)
    {
        //cout << "get seq:" << lft << " rht:" << rht << " cnt:" << cnt << endl;
        vector<Node> data;
        if (cnt <= 0 || lft > rht)
            return data;
        if (rht - lft + 1 <= cnt) {
            for (int i = lft; i <= rht; i++) {
                data.push_back(Node(i, nums[i]));
            }
        } else {
            data = getMaxSeq(lft, rht, nums, cnt);
            cnt -= (int)data.size();

            if (cnt <= 0) {
                sort(data.begin(), data.end(), sortByPos);
                return data;
            }
            vector<Node> tmp;
            for (int i = (int)data.size() - 1; i >= 0; i--) {
                tmp = getSeq(data[i].pos + 1, i + 1 <= (int)data.size() - 1 ? data[i + 1].pos - 1 : rht, nums, cnt);
                cnt -= (int)tmp.size();
                for (int j = 0; j < (int)tmp.size(); j++) {
                    data.push_back(tmp[j]);
                }
                if (cnt <= 0) {
                    sort(data.begin(), data.end(), sortByPos);
                    return data;
                }
            }
            tmp = getSeq(lft, data[0].pos - 1, nums, cnt);
            for (int j = 0; j < (int)tmp.size(); j++) {
                data.push_back(tmp[j]);
            }
            cnt -= (int)tmp.size();
        }
        sort(data.begin(), data.end(), sortByPos);
        return data;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int K = k;
        string resStr = "";
        vector<int> res;
        for (int i = 0; i <= K; i++) {
            //cout << "K:" << K << " order1 cnt:" << i << ", order2 cnt:" << k - i << endl;
            vector<Node> order1 = getSeq(0, (int)nums1.size() - 1, nums1, i);
            vector<Node> order2 = getSeq(0, (int)nums2.size() - 1, nums2, K - i);

            bool flag1 = ((int)order1.size() >= i);
            bool flag2 = ((int)order2.size() >= (K - i));
            if (flag1 && flag2) {
                vector<int> tmp = merge(order1, order2, K);
                string tmpStr = getStr(tmp);
                if (tmpStr > resStr) {
                    resStr = tmpStr;
                    res = tmp;
                }
                //print(order1, order2, res);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> data1;
    vector<int> data2;

    //int tmp1[] = { 3, 9 };
    //int tmp2[] = { 8, 9 };
    //int tmp1[] = { 5, 5, 1 };
    //int tmp2[] = { 4, 0, 1 };
    //int tmp1[] = { 2, 2, 0, 6, 8, 9, 6 };
    //int tmp2[] = { 5, 2, 4, 5, 3, 6, 2 };
    //int tmp1[] = { 8, 0, 4, 4, 1, 7, 3, 6, 5, 9, 3, 6, 6, 0, 2, 5, 1, 7, 7, 7, 8, 7, 1, 4, 4, 5, 4, 8, 7, 6, 2, 2, 9, 4, 7, 5, 6, 2, 2, 8, 4, 6, 0, 4, 7, 8, 9, 1, 7, 0 };
    //int tmp2[] = { 6, 9, 8, 1, 1, 5, 7, 3, 1, 3, 3, 4, 9, 2, 8, 0, 6, 9, 3, 3, 7, 8, 3, 4, 2, 4, 7, 4, 5, 7, 7, 2, 5, 6, 3, 6, 7, 0, 3, 5, 3, 2, 8, 1, 6, 6, 1, 0, 8, 4 };
    //int tmp1[] = { 3, 4, 6, 5 };
    //int tmp2[] = { 9, 1, 2, 5, 8, 3 };
    //int tmp1[] = { 6, 7 };
    //int tmp2[] = { 6, 0, 4 };
    int tmp2[] = {};
    int tmp1[] = { 1, 2 };
    cout << "len1:" << (int)sizeof(tmp1) / sizeof(int) << endl;
    for (int i = 0; i < (int)sizeof(tmp1) / sizeof(int); i++) {
        data1.push_back(tmp1[i]);
    }

    cout << "len2:" << (int)sizeof(tmp2) / sizeof(int) << endl;
    for (int i = 0; i < (int)sizeof(tmp2) / sizeof(int); i++) {
        data2.push_back(tmp2[i]);
    }

    //vector<int> res = s.maxNumber(data1, data2, 5);
    //vector<int> res = s.maxNumber(data1, data2, 3);
    //vector<int> res = s.maxNumber(data1, data2, 5);
    vector<int> res = s.maxNumber(data1, data2, 2);
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
