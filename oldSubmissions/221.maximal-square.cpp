class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //if(matrix.size()==0)
            //return 0;
        //vector<int>nums(matrix[0].size(),0);
        //int ans = 0;
        //for(int i=0;i<matrix.size();++i){
            //for(int j=0;j<matrix[0].size();++j){
                //if(matrix[i][j]=='1'){
                    //nums[j]++;
                //}else{
                    //nums[j]=0;
                //}
            //}
            //ans = max(ans,maxSize(nums));
        //}
        //return ans;
        if(matrix.size()==0)
            return 0;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int ans = 0;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j]=='0'){
                    continue;
                }
                if(i==0 || j==0){
                    dp[i][j] = matrix[i][j]-'0';
                }else{
                    dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
    int maxSize(vector<int>& nums){
        nums.push_back(0);
        int i = 0;
        stack<int>s;
        int ans = 0;
        while(i<nums.size()){
            if(s.empty() || nums[i]>=nums[s.top()]){
                s.push(i++);
            } else{
                int h = nums[s.top()];s.pop();
                int j = (s.empty())?-1:s.top();
                h = min(h,i-j-1);
                    ans = max(ans,h*h);
            }
        }
        return ans;
    }
    
};
