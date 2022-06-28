// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;
        int prev_min = prices[0];
        int price;
        int size = prices.size();
        for(int i = 1; i<size; i++)
        {
            price = prices[i]-prev_min;
            if(price > prof)
                prof = price;
            prev_min = std::min(prev_min,prices[i]);
        }
        return prof;
    }
};