// https://leetcode.com/problems/missing-number/description/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sm = n*(n+1)/2;
        int n_sm = 0;
        for(auto x: nums) n_sm+=x;
        return sm-n_sm;
    }
};