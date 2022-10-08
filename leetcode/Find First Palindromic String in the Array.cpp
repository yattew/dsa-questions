// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/
class Solution {
public:
    bool is_palindrome(string word){
        string w = word;
        reverse(word.begin(), word.end());
        return w == word;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto word: words){
            if(is_palindrome(word))
                return word;
        }
        return string();
    }
};