// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
class Solution {
public:
    int minPartitions(string n) {
        int m = 0;
        for(auto x: n)
        {
            int n = x - '0';
            if(n > m)
                m = n;
        }
        return m;
    }
};