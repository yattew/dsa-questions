// https://takeuforward.org/data-structure/partition-equal-subset-sum-dp-15/
#include <bits/stdc++.h>
using namespace std;
bool solve(vector<int> arr)
{
    int s = 0;
    for (auto x : arr)
        s += x;
    if(s%2!=0)
        return false;
    int k = s/2;
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
            if ((diff > 0 && dp[r - 1][diff - 1]) || arr[r] == c + 1)
                dp[r][c] = true;
            else
                dp[r][c] = dp[r - 1][c];
        }
    }
    return dp[arr.size() - 1][k - 1];
}
int main()
{
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    cout << solve(arr);
}