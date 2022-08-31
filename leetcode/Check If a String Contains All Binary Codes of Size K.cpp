// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int size = s.size();
        if(size<pow(2,k))
            return false;
        int l = 0;
        int r = k;
        string check_str(s,l,r);
        while(r<size){
            st.insert(check_str);
            check_str.erase(0,1);
            check_str.push_back(s[r]);
            r++;
        }
        st.insert(check_str);
        if(st.size()==pow(2,k))
            return true;
        return false;
    }
};