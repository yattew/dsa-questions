// https://takeuforward.org/data-structure/dynamic-programming-house-robber-dp-6/
#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> arr)
{
    vector<int> dp(arr.size(), INT_MIN);
    dp[0] = arr[0];
    int itr = 1;
    while(itr<=arr.size())
    {
        int pick = INT_MIN;
        int not_pick = INT_MIN;
        if(itr-2>=0)
        {
            pick = dp[itr-2] + arr[itr];
        }
        not_pick = dp[itr-1];
        dp[itr] = max(pick,not_pick);
        itr++;
    }
    return dp.back();
}

int robStreet(int n, vector<int> arr)
{
    vector<int> arr1(arr.begin()+1, arr.end());
    vector<int> arr2(arr.begin(), arr.end()-1);
    int res1 = solve(arr1);
    int res2 = solve(arr2);
    return max(res1,res2);
}

int main()
{
    vector<int> arr{1, 5, 1, 2, 6};
    int n = arr.size();
    cout << robStreet(n, arr);
}