class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int deg = 0;
        unordered_map<int,int> mp;
        for(auto x: nums)
            mp[x]++;
        for(auto x: mp){
            if(x.second > deg){
                deg = x.second;
            }
        }
        int l_min = INT_MAX;
        for(auto x: mp){
            if(x.second == deg){
                int l = 0;
                int n = x.first;
                for(int i = 0; i<nums.size(); i++){
                    if(nums[i] == n){
                        l = i;
                        break;
                    }
                }
                int r = 0;
                for(int i = nums.size()-1; i>=0; i--){
                    if(nums[i] == n){
                        r = i;
                        break;
                    }
                }
                l_min = min(l_min, r-l+1);
            }
            
        }
        
        return l_min;
    }
};
