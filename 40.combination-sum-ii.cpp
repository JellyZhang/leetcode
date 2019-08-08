class Solution {
public:
    int static_target;
    vector<int> static_candidates;
    vector<vector<int>> ans;
    vector<int> selected;
    void dfs(int now,int sum){
        if(sum==static_target){
            ans.push_back(selected);
            return;
        }
        else{
            for(int i=now;i<static_candidates.size();++i){
                int temp_sum = sum+static_candidates[i];
                if(temp_sum<=static_target){
                    selected.push_back(static_candidates[i]);
                    dfs(i+1,temp_sum);
                    selected.pop_back();
                }
                while(i+1<static_candidates.size() &&  static_candidates[i]==static_candidates[i+1]){
                    ++i;
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        static_candidates = candidates;
        sort(static_candidates.begin(),static_candidates.end());
        static_target = target;
        ans.clear();
        dfs(0,0);
        return ans;
    }
};
