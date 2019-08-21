class Solution {
public:
    //[]
    //[9,1,2,3,4,5] 6
    //[9,1,2,3,4,5,5,5,5,5,5] 6
    //[2,5,6,0,0,1,2]
    //[4,5,6,0,0,1,2] 3
    //[1,3,1,1,1] 3   <<<----- first = mid = last  brute force
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        //corner
        if(0==len){
            return false;
        }
        int first = 0;
        int last = len-1;
        int mid = (first+last)>>1;
        while(first<=last){
            //cout<<first<<" "<<last<<endl;
            mid = (first+last)>>1;
            if(nums[mid]==target){
                return true;
            }
            //if(nums[mid]==nums[first] && nums[first]==nums[last]){
                ////for(int i=first;i<=last;++i){
                    ////if(nums[i]==target){
                        ////return true;
                    ////}
                ////}
                ////return false; 
                
                ////++first;--last; //trick
                
            //}
            if(nums[mid]==nums[first]){
                first++;
            } //same
            else if(nums[mid]>nums[first]){
                if(target<nums[mid] && target>=nums[first]){
                    last=mid-1;
                }
                else{
                    first=mid+1;
                }
            }
            else{
                if(target>nums[mid] && target<=nums[last]){
                    first=mid+1;
                }
                else{
                    last=mid-1;
                }
            }
        }
        return false;

        
    }
};
