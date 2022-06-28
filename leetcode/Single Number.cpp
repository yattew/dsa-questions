// https://leetcode.com/problems/single-number/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int no=nums.at(0),s = nums.size();
        for(int i=1;i<s;i++)
            no=no^nums[i];
        return no;
    }
};