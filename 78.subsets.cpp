class Solution {
public:
    //[]
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> selected;
        dfs(nums,0,selected,ans);
        return ans;
    }
    void dfs(vector<int>& nums,int start,vector<int>& selected,vector<vector<int>>&ans){
        ans.push_back(selected);
        for(int i=start;i<nums.size();++i){
            selected.push_back(nums[i]);
            dfs(nums,i+1,selected,ans);
            selected.pop_back();
        }
    }
};
