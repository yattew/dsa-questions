class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int n = 0;
        for(auto x: costs){
            if(coins >= x){
                n++;
                coins-=x;
                continue;
            }
            break;
        }
        return n;
    }
};
