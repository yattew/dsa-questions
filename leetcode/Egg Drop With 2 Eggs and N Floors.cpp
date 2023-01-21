vector<int> dp(1001, INT_MAX);
class Solution {
public:
    int drop(int n){
        if(n == 1 || n == 0)
            return n;
        if(dp[n]!=INT_MAX)
            return dp[n];
        int floor_min = INT_MAX;
        for(int i = 2; i<=n; i++){
            int dropped = i-1;
            int ndropped = -1;
            if(dp[n-i]==INT_MAX)
                ndropped = drop(n-i);
            else
                ndropped = dp[n-i];
            floor_min = min(floor_min,1+max(dropped, ndropped));
        }
        dp[n] = floor_min;
        return floor_min;
    }
    int twoEggDrop(int n) {
        return drop(n);
    }
};
