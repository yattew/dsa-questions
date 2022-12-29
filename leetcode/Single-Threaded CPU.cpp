class Solution {
public:
    vector<int> getOrder(vector<vector<int>> tasks) {
        for(int i = 0; i < tasks.size(); ++i) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> remaining;
        
        vector<int> res;
        int curMoment = 0;
        int curIdx = 0;
        while(res.size() < tasks.size()){
            if(remaining.empty() && curIdx < tasks.size())
                curMoment = max(curMoment, tasks[curIdx][0]);
            
            while(curIdx < tasks.size() && tasks[curIdx][0] <= curMoment) {
                remaining.push({tasks[curIdx][1], tasks[curIdx][2]});
                ++curIdx;
            }
            auto next = remaining.top();
            
            remaining.pop();
            curMoment = min(1000000000, curMoment + next[0]);
            res.push_back(next[1]);

        }
        return res;
    }
};