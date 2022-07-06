// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
class Solution {
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(),nums.end());
        int mid = nums.size()/2;
        int ct = 0;
        for(auto x: nums)
        {
            ct+=abs(x-nums[mid]);
        }
        return ct;
    }
};