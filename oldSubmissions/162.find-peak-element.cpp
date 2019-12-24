class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int hi = nums.size()-1;
        int lo = 0;
        int mid1 = (hi+lo)>>1;
        int mid2 = mid1+1;
        while(lo<hi){
            mid1 = (hi+lo)>>1;
            mid2 = mid1+1;
            if(nums[mid1]<nums[mid2]){
                lo = mid2;
            }
            else{
                hi = mid1;
            }
        }
        return lo;
    }
};
