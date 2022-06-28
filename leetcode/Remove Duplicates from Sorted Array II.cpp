// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)
            return nums.size();
        int a=2;
        for(int i=2;i<nums.size();i++)
            if(nums[i]!=nums[a-2])
                nums[a++]=nums[i];
        return a;
    }
};