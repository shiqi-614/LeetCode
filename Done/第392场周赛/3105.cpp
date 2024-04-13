/*
 * =====================================================================================
 *
 *       Filename:  3105.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/11/2024 21:44:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
class Solution {
public:
    bool checkIncrease(int st, int ed, vector<int>& nums) {
        for (int i = st + 1; i <= ed; i++) {
            if (nums[i - 1] >= nums[i]) {
                return false;
            } 
        }
        return true;
    }
    bool checkDecrease(int st, int ed, vector<int>& nums) {
        for (int i = st + 1; i <= ed; i++) {
            if (nums[i - 1] <= nums[i]) {
                return false;
            } 
        }
        return true;
    }

    int longestMonotonicSubarray(vector<int>& nums) {
        int len = (int)nums.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                if (checkIncrease(i, j, nums) || checkDecrease(i, j, nums)) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};
