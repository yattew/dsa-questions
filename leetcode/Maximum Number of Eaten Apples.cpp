class Solution {
public:
    typedef pair<int, int> P; 
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans = 0, n = apples.size();
        priority_queue<P, vector<P>, greater<P>> que;
        int i = 0;
        while(i < n || que.size()){
            if(i < n && apples[i] > 0) 
                que.push({i + days[i] - 1, apples[i]});
			

            while(que.size() && que.top().first < i) 
                que.pop();

            if(que.size()){
                auto p = que.top();
                que.pop();
                if(p.second > 1) 
                    que.push({p.first, p.second - 1});
                ++ans;
            }
            
            ++i;
        }
        return ans;
    }
};
