// https://leetcode.com/problems/permutations-ii/
class Solution {
public:
    void allPermutations(int index,int n,vector<int> nums,vector<vector<int>>& ans){
        if(index==n-1){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<n;i++){
            if(i!=index && nums[i]==nums[index])continue;
            swap(nums[i],nums[index]);
            allPermutations(index+1,n,nums,ans);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        allPermutations(0,nums.size(),nums,ans);
        return ans;
    }
}