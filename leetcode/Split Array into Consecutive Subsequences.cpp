// https://leetcode.com/problems/split-array-into-consecutive-subsequences/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> sub_end;
        for(auto x: nums)
            freq[x]++;
        for(auto x: nums){
            if(freq[x]==0)
                continue;
            freq[x]--;
            if(sub_end.find(x-1)!=sub_end.end() && sub_end[x-1]>0){
                sub_end[x-1]--;
                sub_end[x]++;
                continue;
            }
            if(freq[x+1]>0&&freq[x+2]>0){
                sub_end[x+2]++;
                freq[x+1]--;
                freq[x+2]--;
            }
            else return false;
        }
        for(auto x: freq)
            if(x.second>0)
                return false;
        return true;
    }
};