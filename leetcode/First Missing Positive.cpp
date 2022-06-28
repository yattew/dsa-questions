// https://leetcode.com/problems/first-missing-positive/
class Solution {
public:
int firstMissingPositive(vector<int> &n)
{
    unsigned len = n.size();
    for (int i = 0; i < len; i++)
        if (n[i] <= 0)
            n[i] = INT_MAX;
    for(int i = 0; i< len; i++)
        if(n[i]!=0 && abs(n[i])<=len)
        {
            int el = abs(n[i])-1;
            if(n[el]>0)
                n[el] *=-1; 
        }
    for(int i = 1; i<=len; i++)
        if(n[i-1]>0)
            return i;
    return n.size()+1;
}
};