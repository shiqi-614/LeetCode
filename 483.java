import java.math.BigInteger;
class Solution {
    String getRes(int cnt) {
        String res = "";
        for (int i = 0; i < cnt; i++) {
            res +="1";
        }
        return res;
    }

    BigInteger checkVal(int len, int intBase) {
        BigInteger val = new BigInteger("0");    
        BigInteger base = new BigInteger(String.valueOf(intBase));
        BigInteger mul = new BigInteger("1");
        for (int i = 0; i < len; i++) {
            val = val.add(mul);
            mul = mul.multiply(base);
        }
        return val;
    }

    boolean check(int len, BigInteger val) {
        int lft = 2;
        int rht = val -1;
        while(lft < rht) {
            int mid = (lft + (rht - lft) / 2);
            BigInteger tmp = checkVal(len, mid);
            int num = tmp.compareTo(val);
            if (num > 0) {
                rht = mid - 1;
            } else if (num == 0) {
                return true;
            } else if (num < 0) {
                lft = mid + 1;
            }
        }
        return false;
    }

    public String smallestGoodBase(String n) { 
        BigInteger val = new BigInteger(n);
        int maxLen = getMaxLen(val);
        int minLen = 2;
        for (int i = maxLen; i >= minLen; i++) {
            if (check(i, val)) {
                return getRes(i);
            }
        }
    }
}
