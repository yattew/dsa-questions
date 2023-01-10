class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i = 0; i<num.length(); i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }       
        reverse(res.begin(), res.end());
        while(k>0 && res.length()){
            res.pop_back();
            k--;
        }
        while(res.length() && res[0] == '0'){
            res.erase(0,1);
        }
        if(res.length()==0){
            return "0";
        }
        return res;
    }
};
