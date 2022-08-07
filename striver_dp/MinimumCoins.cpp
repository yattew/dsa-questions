// https://takeuforward.org/data-structure/minimum-coins-dp-20/
#include <bits/stdc++.h>
using namespace std;
int min(vector<int> arr)
{
    int mx = arr[0];
    for (auto x : arr)
        mx = min(mx, x);
    return mx;
}
int solve(vector<int> arr, int k)
{
    vector<int> dp(k + 1, -1);
    int it = k;
    dp[it] = 0;
    it--;
    while (it >= 0)
    {
        vector<int> optn;
        for (auto jmp : arr)
            if (it + jmp < k + 1)
                optn.push_back(dp[it + jmp] + 1);
        dp[it] = min(optn);
        it--;
    }
    return dp[0];
}
int main()
{
    vector<int> arr{1, 2, 3};
    int k = 7;
    cout << solve(arr, k);
}