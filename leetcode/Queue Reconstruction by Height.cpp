// https://leetcode.com/problems/queue-reconstruction-by-height/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        unsigned len = people.size();
        sort(people.begin(),
             people.end(),
             [](vector<int> &p1, vector<int> &p2)
             {
                 if (p1[0] == p2[0])
                     return p1[1] < p2[1];
                 return p1[0] > p2[0];
             });
        vector<vector<int>> res;
        for (int i = 0; i < len; i++)
            res.insert(res.begin()+people[i][1],people[i]);
        return res;
    }
};