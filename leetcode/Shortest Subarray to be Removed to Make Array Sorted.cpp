// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), r = n-1;
        while(r > 0 and arr[r-1] <= arr[r]) --r;
        
        int ans = r;
        for(int l=0; l < r and (l == 0 or arr[l-1] <= arr[l]); ++l){
            while(r < n and arr[r] < arr[l]) ++r;
            ans = min(ans, r-l-1);
        }
        return ans;
    }
};