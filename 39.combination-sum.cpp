#include <vector>
class Solution {
public:
    int static_target;
    vector<int> static_candidates;
    vector<vector<int>> ans;
    vector<int> selected;
    void dfs(int now,int sum){
        if(static_target ==sum){
            ans.push_back(selected);
        }
        else{
            for(int i=now;i<static_candidates.size();++i){
                int temp_sum = sum+static_candidates[i];
                if(temp_sum<=static_target){
                    selected.push_back(static_candidates[i]);
                    dfs(i,temp_sum);
                    selected.pop_back();
                }
            }
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        static_target = target;
        static_candidates = candidates;
        ans.clear();
        selected.clear();
        dfs(0,0);
        return ans;
    }
};
