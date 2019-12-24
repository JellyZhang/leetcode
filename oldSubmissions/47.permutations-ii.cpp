class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        bool* visited = new bool[nums.size()];
        for(int i=0;i<nums.size();++i){
            visited[i]=false;
        }
        vector<vector<int>> ans;
        vector<int> selected;
        ans.clear();
        selected.clear();
        sort(nums.begin(),nums.end());
        dfs(nums,selected,visited,ans);
        return ans;
    }
    void dfs(vector<int> nums,vector<int>& selected,bool visited[],vector<vector<int>>& ans){
        //cout<<"!";
        //for(int i=0;i<selected.size();++i){
            //cout<<selected[i]<<" ";
        //}
        if(selected.size()==nums.size()){
            ans.push_back(selected);
        }
        else{
            for(int i=0;i<nums.size();++i){
                if(!visited[i]){
                    visited[i] =true;
                    selected.push_back(nums[i]);
                    dfs(nums,selected,visited,ans);
                    selected.pop_back();
                    visited[i]=false;
                    while(i+1<nums.size() && nums[i]==nums[i+1]){
    //                    cout<<"do";
                        ++i;
                    }
                }
            }
        }
    }
};
