// https://takeuforward.org/data-structure/subset-sum-equal-to-target-dp-14/
#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr, int k)
{
    vector<vector<bool>> dp(
        arr.size(),
        vector<bool>(k, false));
    int len = arr.size();
    for (int i = 0; i < k; i++)
        if (i + 1 == arr[0])
            dp[0][i] = true;
    for (int r = 1; r < len; r++)
    {
        for (int c = 0; c < k; c++)
        {
            int diff = c + 1 - arr[r];
            // cout << r << " " << arr[r] << " " << diff << endl;
            if ((diff > 0 && dp[r - 1][diff-1]) || arr[r] == c+1)
                dp[r][c] = true;
            else
                dp[r][c] = dp[r - 1][c];
        }
    }
    // for (auto x : dp)
    // {
    //     for (auto y : x)
    //         cout << y << " ";
    //     cout << endl;
    // }
    return dp[arr.size()-1][k-1];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    cout << solve(arr, k);
}