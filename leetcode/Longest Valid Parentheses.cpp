// https://leetcode.com/problems/longest-valid-parentheses/
class Solution {
public:
    int longestValidParentheses(string s) {
        return solution(s);
    }
    stack<pair<int, int>> fixRanges(stack<pair<int, int>> ranges)
    {
        while (!ranges.empty())
        {
            pair<int, int> top = ranges.top();
            ranges.pop();
            if (ranges.empty())
            {
                ranges.push(top);
                return ranges;
            }
            pair<int, int> top2 = ranges.top();
            ranges.pop();
            if (top.first == top2.second + 1)
            {
                pair<int, int> res = make_pair(top2.first, top.second);
                ranges.push(res);
                continue;
            }
            if (top.first == top2.first - 1)
            {
                pair<int, int> res = make_pair(top.first, top.second);
                ranges.push(res);
                continue;
            }
            ranges.push(top2);
            ranges.push(top);
            return ranges;
        }
        return ranges;
    }

    pair<int, int> getMaxRange(stack<pair<int, int>> ranges)
    {
        pair<int, int> maxRange = ranges.top();
        while (!ranges.empty())
        {
            pair<int, int> currRange = ranges.top();
            ranges.pop();
            if (currRange.second - currRange.first > maxRange.second - maxRange.first)
            {
                maxRange = currRange;
            }
        }
        return maxRange;
    }

    int solution(string s)
    {
        stack<pair<char, int>> stck;
        stack<pair<int, int>> ranges;
        for (int i = 0; i < s.length(); i++)
        {
            if (stck.empty())
            {
                stck.push(make_pair(s[i], i));
                continue;
            }
            if (s[i] == ')')
            {
                if (stck.top().first == '(')
                {
                    ranges.push(make_pair(stck.top().second, i));
                    stck.pop();
                    ranges = fixRanges(ranges);
                }
                continue;
            }
            stck.push(make_pair('(', i));
        }
        ranges = fixRanges(ranges);
        if(ranges.empty())
        {
            return 0;
        }
        pair<int, int> maxRange = getMaxRange(ranges);
        // cout << "left :" << maxRange.first << "right: " << maxRange.second << endl;
        return maxRange.first,maxRange.second-maxRange.first+1;
    }
};