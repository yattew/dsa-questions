// https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int i = n;
        vector<int> temp;
        for (int j = 0; j < i; j++)
            temp.push_back(0);
        vector<vector<int>> res = solution(temp, i, 1);
        vector<string> finalResult;
        for (auto x : res)
        {
            string curr;

            for (auto y : x)
            {
                curr+="(";
                for (int k = 0; k < y; k++)
                    curr+=")";
            }
            finalResult.push_back(curr);
        }
        return finalResult;
    }
    vector<vector<int>> solution(vector<int> arr, int awailable, int idx)
    {
        if (arr.size() == idx)
        {
            vector<vector<int>> ret;
            vector<int> temp;
            temp.push_back(awailable);
            ret.push_back(temp);
            return ret;
        }
        vector<vector<int>> result;
        for (int i = 0; i <= idx; i++)
        {
            if (arr.size() - idx > awailable - i)
            {
                break;
            }

            vector<vector<int>> curr;
            vector<vector<int>> retRes = solution(arr, awailable - i, idx + 1);
            int currBrackets = min(i, awailable);
            for (int j = 0; j < retRes.size(); j++)
            {
                vector<int> temp;
                temp.push_back(currBrackets);
                for (int k = 0; k < retRes[j].size(); k++)
                {
                    temp.push_back(retRes[j][k]);
                }
                curr.push_back(temp);
            }
            result.insert(result.end(), curr.begin(), curr.end());
        }
        return result;
    }
};