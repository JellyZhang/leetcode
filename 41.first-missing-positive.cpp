class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        int j = len-1;
        while(i<=j){
            if(nums[i]==i+1){
                ++i;
                continue;
            }
            // nums[i] looks for pos nums[i]-1
            else if(nums[i]>0 && nums[i]-1<=j && nums[nums[i]-1]!=nums[i]){
                swap(nums[nums[i]-1],nums[i]);
            }
            else{
                swap(nums[j--],nums[i]);
            }
        }
        if(i==0){
            return 1;
        }
        else{
            return nums[i-1]+1;
        }
    }
};
