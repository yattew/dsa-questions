// https://leetcode.com/problems/brick-wall/description/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) 
    {
        unordered_map<int, int> edge_frequency;
        int max_frequency = 0;
        for(int row=0; row<wall.size(); row++)
        {
            int edge_postion = 0;
            for(int brick_no=0; brick_no< wall[row].size() -1; brick_no++)
            { 
                int current_brick_length = wall[row][brick_no];
                edge_postion = edge_postion + current_brick_length ; 
                edge_frequency[edge_postion]++;
                max_frequency = max(edge_frequency[edge_postion],max_frequency);
            }
        }
        return wall.size() - max_frequency;
    }
};