// https://leetcode.com/problems/maximum-length-of-pair-chain/
bool cmp(vector<int> a, vector<int> b){
        return a[1] < b[1];
}
class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int n = 1;
        int it = 1;
        int end = pairs[0][1];
        for(; it<pairs.size(); it++){
            if(end<pairs[it][0]){
                end = pairs[it][1];
                n++;
            }
        }
        return n;
    }
};