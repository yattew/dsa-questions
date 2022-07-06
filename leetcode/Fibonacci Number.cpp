// https://leetcode.com/problems/fibonacci-number/
class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        for(; n>1; n--)
        {
            int c = b;
            b = a+b;
            a = c;
        }
        return b;
    }
};