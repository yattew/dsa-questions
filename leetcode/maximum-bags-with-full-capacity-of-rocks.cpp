class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i= 0; i<capacity.size(); i++){
            capacity[i]-=rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        int full_count = 0;
        for(auto remaining: capacity){
            additionalRocks-=remaining;
            if(additionalRocks>=0){
                full_count+=1;
            }
            else{
                break;
            }
        }
        return full_count;
    }
};