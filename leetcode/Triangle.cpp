// https://leetcode.com/problems/triangle/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>());
        int r_it = triangle.size()-1;
        for(auto x: triangle[r_it])
            dp[r_it].push_back(x);
        r_it--;
        for(; r_it>=0; r_it--)
            for(int c_it = 0; c_it<triangle[r_it].size(); c_it++)
                dp[r_it].push_back(min(
                    dp[r_it+1][c_it],
                    dp[r_it+1][c_it+1]
                ) + triangle[r_it][c_it]);
        return dp[0][0];
    }
};