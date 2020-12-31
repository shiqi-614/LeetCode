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

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))
const int N=1e5+5;
const int MOD = 1e9 + 7;
 
struct node
{
	int lft,rht;
	int sum;
	int mid(){return MID(lft,rht);}
};
 
 
struct Segtree
{
	node tree[N*4];
	void build(int lft,int rht,int ind)
	{
		tree[ind].lft=lft;	tree[ind].rht=rht;
		tree[ind].sum=0;
		if(lft==rht) tree[ind].sum = 0;
		else 
		{
			int mid=tree[ind].mid();
			build(lft,mid,LL(ind));
			build(mid+1,rht,RR(ind));
			tree[ind].sum=tree[LL(ind)].sum+tree[RR(ind)].sum;
		}
	}
	void updata(int pos,int ind,int valu)
	{
		if(tree[ind].lft==tree[ind].rht) tree[ind].sum+=valu;
		else 
		{
			int mid=tree[ind].mid();
			if(pos<=mid) updata(pos,LL(ind),valu);
			else updata(pos,RR(ind),valu);
			tree[ind].sum=tree[LL(ind)].sum+tree[RR(ind)].sum;
		}
	}
	int query(int st,int ed,int ind)
	{
		int lft=tree[ind].lft,rht=tree[ind].rht;
		if(st<=lft&&rht<=ed) return tree[ind].sum;
		else 
		{
			int mid=tree[ind].mid();
			int sum1=0,sum2=0;
			if(st<=mid) sum1=query(st,ed,LL(ind));
			if(ed>mid) sum2=query(st,ed,RR(ind));
			return sum1+sum2;
		}
	}
}seg;
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int len = (int)instructions.size();
        seg.build(1, N - 1, 1);
        int res = 0;
        for (int i = 0; i < len; i++) {
            seg.updata(instructions[i], 1, 1);
            int tmp = N;
            if (instructions[i] > 1) {
                tmp = min(tmp, seg.query(1, instructions[i] - 1, 1));
            } else {
                tmp = 0;
            }
            tmp = min(tmp, seg.query(instructions[i] + 1, N - 1, 1));
            res = (res + tmp) % MOD;
        }
        return res;
    }
};
int main()
{
    vector<int> data;
    data.push_back(1);
    data.push_back(5);
    data.push_back(6);
    data.push_back(2);
    Solution s;
    cout<<s.createSortedArray(data)<<endl;
    return 0;
}


