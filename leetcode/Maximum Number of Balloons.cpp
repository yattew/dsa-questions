// https://leetcode.com/problems/maximum-number-of-balloons/description/
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> fmap;
        for(auto x: text)
            fmap[x]++;
        string s = "balloon";
        int n = 0;
        while(true)
        {
            int flag = true;
            for(auto x: s)
                if(fmap[x]-- >0);
                else 
                {
                    flag = false;
                    break;
                }
            if(flag) 
                n++;
            else 
                break;
        }
        return n;
    }
};