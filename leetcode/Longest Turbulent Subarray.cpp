// https://leetcode.com/problems/longest-turbulent-subarray/
class Solution {
public:
        int getSign(int x, int y) {
        if (x < y)
            return -1;
        else if (x > y)
            return 1;
        return 0;  
    }

    int maxTurbulenceSize(vector<int>& arr) {
        int start = 0;
        int end = 0;
        int max = 0;
        int size = arr.size();
        int sign = 0;
        int lastSign = 0;
        while (end < size) {
            int curSize = end - start + 1;
            if (end + 1 == size)
                return std::max(max, curSize);
            sign = getSign(arr[end], arr[end+1]);
            if (sign == 0) {
                max = std::max(max, curSize);
                start = end + 1;
            }
            else if (sign == lastSign) {
                max = std::max(max, curSize);
                start = end;
            }
            end++;
            lastSign = sign;
        }
        return max;
    }
};