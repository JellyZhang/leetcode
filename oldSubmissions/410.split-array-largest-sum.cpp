class Solution {
public:
    bool doable(vector<int>&nums,int cuts,long long limit){
        long long acc = 0;
        for(auto num : nums){
            if(num>limit)
                return false;
            else if(acc+num<=limit){
                acc+=num;
            }else{
                cuts--;
                acc = num;
                if(cuts<0)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        //vector<vector<long long>>dp(nums.size()+1,vector<long long>(m+1,INT_MAX));
        //vector<long long>sub(nums.size()+1,0);
        //for(int i=0;i<nums.size();++i){
            //sub[i+1] = sub[i]+nums[i];
        //}
        //dp[0][0] = 0;
        //for(int i=1;i<=nums.size();++i){
            //for(int j=1;j<=m;++j){
                //for(int k=0;k<i;k++){
                    //dp[i][j] = min(dp[i][j],max(dp[k][j-1],sub[i]-sub[k]));
                //}
            //}
        //}
        //return dp[nums.size()][m];
        long long lo = 0 ,hi = 0;
        for(long long num:nums){
            lo = max(lo,num);
            hi += num;
        }
        //for(int i=lo;i<=hi;++i){
            //cout<<i<<" ";
            //if(doable(nums,m-1,i))
                //cout<<"true ";
            //else 
                //cout<<"false ";
        //}
        long long mid = (lo+hi)>>1;
        while(lo<=hi){
            mid = (lo+hi)>>1;
            if(doable(nums,m-1,mid)){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};
