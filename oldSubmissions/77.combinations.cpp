class Solution {
public:
    // 0,0
    // 1,1
    // 4,2
    // 100,20
    // 2,4  k>n
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> nums;
        for(int i=1;i<=n;++i){
            nums.push_back(i);
        }
        vector<int>selected;
        dfs(nums,0,k,selected,ans);
        return ans;
    }
    void dfs(vector<int>& nums,int start,int steps,vector<int>& selected,vector<vector<int>>& ans){
        if(!steps){
            ans.push_back(selected);
            return;
        }
        for(int i=start;i<nums.size();++i){
            selected.push_back(nums[i]);
            dfs(nums,i+1,steps-1,selected,ans);
            selected.pop_back();
        }
    }
};
