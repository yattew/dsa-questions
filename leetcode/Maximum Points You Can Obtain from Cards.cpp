// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int r = 0;
        int l = 0;
        int sm = 0;
        int len = cardPoints.size();
        for (int i = 0; i < k; i++)
        {
            sm += cardPoints[len - 1 - i];
            r++;
        }
        cout<<sm<<endl;
        int sm_max = sm;
        while (l < k)
        {
            sm = sm - cardPoints[len - r] + cardPoints[l];
            cout<<sm<<" "<<sm_max<<endl;
            if ( sm > sm_max)
            {
                sm_max = sm;
            }
            r--;
            l++;
        }
        cout<<sm_max<<endl;
        return sm_max;
    }
};