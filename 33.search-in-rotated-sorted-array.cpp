class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0){
            return -1;
        }
        int lo = 0;
        int hi = nums.size()-1;
        int mid ;
        while(lo<hi){
            mid = (lo+hi)>>1;
            if(target == nums.at(mid)){
                return mid;
            }
            else if(nums.at(mid)>nums.at(hi)){
                
                if(target<nums.at(mid) && target>nums.at(hi)){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            else{
                if(target > nums.at(mid) && target <= nums.at(hi)){
                    lo = mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
        }
        if( nums.at(lo)==target){
            return lo;
        }
        return -1;
        
    }
};
