class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //int len = nums.size();
        //sort(nums.begin(),nums.end());
        //vector<vector<int>> ans;
        //ans.push_back({});
        //int n=1;
        //for(int i=0;i<len;++i){
            //vector<vector<int>> temp = ans;
            //for(int j=temp.size()-n;j<temp.size();++j){
                //temp[j].push_back(nums[i]);
                //ans.push_back(temp[j]);
            //}
            //if(i+1<len && nums[i+1]==nums[i]){
                //if(n==0){
                    //n=temp.size();
                //}
            //}
            //else{
                //n=ans.size();
            //}
        //}
        //return ans;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans = {{}};
        int start=0;
        for(int i=0;i<nums.size();++i){
            if(i>0 && nums[i]!=nums[i-1])
                start=0;
            vector<vector<int>> temp = ans;
            for(int end=temp.size();start<end;start++){
                temp[start].push_back(nums[i]);
                ans.push_back(temp[start]);
            }
        }
        return ans;
        
    }
};
