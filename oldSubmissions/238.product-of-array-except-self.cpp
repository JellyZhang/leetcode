class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int frombegin = 1;
        int fromend = 1;
        vector<int>ans(nums.size(),1);

        //for(int i=1;i<nums.size();++i){
            //frombegin[i] = frombegin[i-1]*nums[i-1];
            //fromend[i] = fromend[i-1] * nums[n-i];
        //}
        for(int i=0;i<nums.size();++i){
            ans[i]*=frombegin;
            frombegin*=nums[i];
            ans[n-1-i]*=fromend;
            fromend*=nums[n-1-i];
            //ans[i] = frombegin[i]*fromend[n-1-i];
        }
        return ans;
    }
};
