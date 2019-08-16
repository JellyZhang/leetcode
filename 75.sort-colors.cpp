class Solution {
public:
    // all 0
    // all 1
    // all 2
    // []
    // [1,2,2,1,1,2] no 0
    // [0,2,0,2,2,2,0,0] no 1
    // [1,0,1,0,0,1,0] no 2
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        //pos to insert 0 and 2
        for(int p=0;p<=j;++p){
            if(nums[p]==0){
                std::swap(nums[p],nums[i++]);
            }
            else if(nums[p]==2){
                std::swap(nums[p--],nums[j--]);
                //after swap,num[p] can be 0 or 1 or 2
                //so do it again;
            }
        }
        return;
    }
};
