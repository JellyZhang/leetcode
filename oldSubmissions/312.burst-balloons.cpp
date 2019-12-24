class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int len=1;1+len<nums.size();++len){
            //cout<<"len="<<len<<endl;
            for(int l=1;l+len-1<=n-2;++l){
                //cout<<"l="<<l<<endl;
                int r = l+len-1;
                int temp_max = 0;
                for(int k=l;k<=r;++k){
                    int temp = dp[l][k-1]+dp[k+1][r];
                    temp+=nums[k]*nums[l-1]*nums[r+1];
                    temp_max = max(temp_max,temp);
                }
                dp[l][r] = temp_max;
            }
        }
        //for(int i=0;i<n;++i){
            //for(int j=0;j<n;++j){
                //cout<<dp[i][j]<<" ";
            //}
            //cout<<endl;
        //}
        return dp[1][n-2];
    }
};
