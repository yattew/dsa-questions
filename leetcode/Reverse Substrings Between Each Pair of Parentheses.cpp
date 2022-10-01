// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/
class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack<int> st;
        string answer="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')')
            {
                reverse(s.begin()+st.top()+1,s.begin()+i);
                st.pop();
            }
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!= '(' && s[i]!=')')
                answer=answer+s[i];
        }
        return answer;
    }
};