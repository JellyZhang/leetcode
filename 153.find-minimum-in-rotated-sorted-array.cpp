class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0)
            return -1;
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<hi){
            int mid = (lo+hi)>>1;
            if(nums[mid]>nums[hi]){ //why not >=nums[lo] ???
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        return nums[lo];
    }
};
