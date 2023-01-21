class Solution {
public:

    string largestGoodInteger(string num) {
        string m = "-1";
        for(int i = 0; i<num.length()-2; i++){
            string s = num.substr(i,3);
            if(s[0] == s[1] && s[0] == s[2]){
                int n = stoi(s);
                if(stoi(m) < n)
                    m = s;
            }
        }
        if(m == "-1")
            return "";
        return m;
    }
};
