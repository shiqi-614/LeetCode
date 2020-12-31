#include <cstdlib>
#include<unordered_set>
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

typedef long long LL;
#define PB push_back
#define MP make_pair

const int MOD = 1e9 + 7;
const int BASE = 31;

class Solution {
public:
    vector<int> prefix;
    vector<int> mul;
    int getHash(int lft, int rht) {
        return ((prefix[rht] - ((LL)prefix[lft - 1] * mul[rht - lft  + 1]) % MOD) + MOD) % MOD;
    }
    int distinctEchoSubstrings(string text) {
        int len = (int)text.size();
        mul.resize(len + 1); mul[0] = 1;
        prefix.resize(len + 1); prefix[0] = 0;
        for (int i = 1; i <= len; i++) {
            mul[i] = ((LL)mul[i - 1] * BASE ) % MOD;
            prefix[i] = ((LL)prefix[i - 1] * BASE + (text[i - 1] - 'a' + 1)) % MOD;
        }
        set<int> vis;
        int res = 0;
        for (int i = 1; i <= len; i++) {
            for (int j = i + 1; j <= len; j++) {
                int sLen = j - 1 - i + 1;
                if (j + sLen - 1 <= len)  {
//                    cout<<i<<" "<<j<<endl;
                    int hashLeft = getHash(i, j - 1);
//                    cout<<hashLeft<<" st:"<<i<<" ed:"<<j-1<<endl;
//                    LL hashRight = getHash(j, j + sLen - 1, prefix, mul);
                    if (vis.find(hashLeft) == vis.end() && hashLeft == getHash(j, j + sLen - 1)) {
//`                        cout<<(int)res.size()<<endl;
                        vis.insert(hashLeft);
                        res++;
                    }
                }
            }
//            cout<<"i:"<<i<<endl;
        }
        return res;
    }
};

int main() {
    Solution s;
//    cout<<s.distinctEchoSubstrings("abcabcabc")<<endl;
//    cout<<s.distinctEchoSubstrings("leetcodeleetcode")<<endl;
    cout<<s.distinctEchoSubstrings("aaaaaaaaaa")<<endl;

//   cout<<s.distinctEchoSubstrings("tkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnra")<<endl;
//   cout<<s.distinctEchoSubstrings("ibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynoc")<<endl;
//    cout<<s.distinctEchoSubstrings("ibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynocibnlogcpqhuabiqtjmcpmjzzgxslnekyaiovaidcbbblnywdchfcefzbfoczkoxpypszpfptirigscjhduhysnhydtirynowynoc")<<endl;
//    cout<<s.distinctEchoSubstrings("wdyihepunnmlqjkpnrrzjdnysubneoiafptyurqyoiglsodisssyouhcjpwvdwfnboodwukaizlsifotxxavqybwmxpanaswhhfikcucnmdeqiyttkdqyhomzpfasrmmiurrouxbotovucdmqesiyrdkhlxbnbowwuetdyzhbkimokqqpwhdlxxdbktstkvseiylcrfgmyiatkjqsuwhbkbxuatiolxnhespqvgppzczakrzvhmkxakyipjtsaiyfbxwgrbqqfdrebrtryxdzghlnqgttldoiwezugexbdqikooyccjbflfmowgugwnizlmbtlruldgjriyngfhcigonvdgtjclopdzzwslglnwxjnxepcxcxwofmnkbkpcntxxmoomluhzkjidzxbchtbctinlqrlgihrnppvvqhkeasftmsijgqgntpoxsfszuzpvhvrxbxpfqrlgafxssaiyiismmjiuopbslrdxdzcnupdaeprmgzujmznhmecpzppbkjhlueynamrjgpxqwsvoyyhbmtnexylmfuemcduusueuxpsgfooultqfeuzhlxiyjquagryzsxpabbtmmypbgjzqewsrvtnxvmoamnuamixublfcxlecdpjpdmcztdrygvukldkiooenwkuqkmgllhppvqiqbawddynaqaejvqaqdeuwtqtcfxvbydhiwkrkekazxaftzeqrwsjqrrtorjfsonshmkzwdvexfobceyclpurtdaotjoozawhhvxkesbnauvbfafrvoewmxamxsxdkvhfywfzqbwnuoyqotmyuyveuallhrwuwimuefmzprwmwhasarytunalgebijmlupxchiiqvzeeelprgwbdsgwnjzjhkvehlsgwynuocjhtjehuidszgqbiuvhtbxsegogbffekerpidkuqqvmpwlsaneqanzwwqdjvskamjmdrjzwkugzvppfenlbrapsnnaozqiwqatkqqnfmnxbdgfztoticwvjzcwolzcrucposxjacpafzbvbcmgugtpdkqfdyrpjxnzpnycbqqxwrvnpoerkutiucekgyfyddfpddqegauyuaarmqarwizvswquybdhirqincciydlqeuvlkiivqudnyuqsgrquiupwhpgvwltwzsqtiaqixnvtvqgbsmauditfeqevpinlxmdmjsnczuukbihgovjnejeknwywnneuhjtumujlhpeikfvnbscwmfzhltswbnqkqkrqfqfdzyvnlcpuevhjcyglshlvblochtqcfjjeqeowkowtwoysvvzraxgmvaeuogoahndfgzwohqbiuhlofablccghrcahygjhjiboufjhtznxxdewlsagxhbjmqrygvkikpnoxuubzwqjrnprzpggreqfpawnynqmmzkhexjjcrhzckgfmpkwyuwsqkspjylnzteirhqlbnecejifjliygjxoepvzterssaplerwbnppbivevuhsxuiczmyiuvdsovqnrazsuyuufiaksphalquhoxwwsmoyicmklqcqstorqhemmqsnwfcaznodlogqwhgdkvfnxkgwmlidtxfoulzqbpxjdrzmfgnvcvghwwtznqkvxtcvpfhxykqwclocogyqqdqbjoqvrwgxrflnnzealdadyayxxpnyhkkiueejbysiggloswuydlpvskkdcytwbbdkcmtpzrglxgxilmnkkqxzweimvrcqflqjmcweqbjztwuutzqnninjremjrshckfcycxhgxxpbzulubrjhiiighpzbqwltlfcqbxqdgumwsfcztsgnkbsxojeefeddtbtyztseebyqhqcfeacndmixmlcbnpproynpgiqbktzlawzrgjzqlbnnaskrxywwaikjfdztqnqvigpnvmtqtuzrgnkzbfmigykhvsuabstexeqmmywbaospgtfggqgxdfmgtnrwzxzqbqctnezkbfjsmvknqm")<<endl;
    return 0;
}

