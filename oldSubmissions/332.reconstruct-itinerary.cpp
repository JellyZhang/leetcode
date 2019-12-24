class Solution {
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> flights;
    vector<string>ans;
    void dfs(string cur){
        auto &edges = flights[cur];
        while(!edges.empty()){
            string nxt = edges.top();edges.pop();
            dfs(nxt);
        }
        ans.push_back(cur);
    }
    
    public:
        vector<string> findItinerary(vector<vector<string>>& tickets) {
            for(auto ticket:tickets){
                flights[ticket[0]].push(ticket[1]);
            }
            dfs("JFK");
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };
