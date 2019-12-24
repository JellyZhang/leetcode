/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

// @lc code=start
class Solution {
public:
    const int max_level = 2;
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        //vector<vector<int>>nums;
        //for(auto& par:A){
            //nums.push_back({par[0],1});
            //nums.push_back({par[1],-1});
        //}
        //for(auto& par:B){
            //nums.push_back({par[0],1});
            //nums.push_back({par[1],-1});
        //}
        //sort(nums.begin(),nums.end(),[](vector<int>a,vector<int>b){
                //if(a[0]!=b[0]){
                    //return a[0]<b[0];
                    //} else{
                    //return a[1]>b[1];
                    //}
                //});
        //int cur_level = 0;
        //int inPos = 0;
        //vector<vector<int>>ans;
        //for(int i=0;i<nums.size();++i){
            ////cout<<nums[i][0]<<" "<<nums[i][1]<<endl;
            //cur_level += nums[i][1];
            //if(cur_level == max_level){
                //inPos = nums[i][0];
            //} else if(cur_level - nums[i][1] == max_level){
                //ans.push_back({inPos,nums[i][0]});
            //}
        //}
        //return ans;
        vector<vector<int>> ans;
        int i = 0;
        int j = 0;
        while(i<A.size() && j<B.size()){
            int max_in = max(A[i][0],B[j][0]);
            int min_out = min(A[i][1],B[j][1]);
            if(max_in<=min_out){
                ans.push_back({max_in,min_out});
            }
            if(A[i][1]<B[j][1]){
                i++;
            }else{
                j++;
            }
        }
        return ans;
    }
};
// @lc code=end
