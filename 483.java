import java.math.BigInteger;
class Solution {
    String getRes(int cnt)
    {
        String res = "";
        for (int i = 0; i < cnt; i++) {
            res += "1";
        }
        return res;
    }

    BigInteger checkVal(int len, BigInteger base)
    {
        BigInteger val = new BigInteger("0");
        BigInteger mul = new BigInteger("1");
        for (int i = 0; i < len; i++) {
            val = val.add(mul);
            mul = mul.multiply(base);
        }
        return val;
    }

    BigInteger check(int len, BigInteger val)
    {
        BigInteger lft = BigInteger.TWO;
        BigInteger rht = val;
        while (true) {
            if (lft.compareTo(rht) >= 0)
                break;
            BigInteger sum = lft.add(rht);
            BigInteger mid = sum.divide(BigInteger.TWO);
            BigInteger tmp = checkVal(len, mid);
            int num = tmp.compareTo(val);
            System.out.println("lft:" + lft + " mid:" + mid + " rht:" + rht);
            if (num > 0) {
                rht = mid.subtract(BigInteger.ONE);
            } else if (num == 0) {
                return mid;
            } else if (num < 0) {
                lft = mid.add(BigInteger.ONE);
            }
        }
        if (lft.compareTo(rht) == 0 ) {
            BigInteger tmp = checkVal(len, lft);
            if (tmp.compareTo(val) == 0) {
                return lft;
            }
        }
        return new BigInteger("-1");
    }

    int getMaxLen(BigInteger val)
    {
        BigInteger tmp = val;
        int cnt = 0;
        while (true) {
            if (tmp.compareTo(BigInteger.ZERO) <= 0) {
                break;
            }
            cnt++;
            tmp = tmp.divide(BigInteger.TWO);
        }
        return cnt;
    }
    public String smallestGoodBase(String n)
    {
        BigInteger val = new BigInteger(n);
        int maxLen = getMaxLen(val);
        int minLen = 2;
        BigInteger invalid = new BigInteger("-1");
        for (int i = maxLen; i >= minLen; i--) {
            BigInteger res = check(i, val);
            System.out.println("len:" + i + " " + res);
            if (invalid.compareTo(res) != 0) {
                return res.toString();
            }
        }
        return n;
    }
}
