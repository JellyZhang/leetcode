class Solution {
public:
    // []
    // [1]
    // [0,0,0,0,1,1]
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len==0){
            return 0;
        }
        int i=1;int j=1;
        int cnt=1;
        int record=nums[0];
        while(i<len){
            if(nums[i]==record){
                cnt++;
                if(cnt==2){
                    swap(nums[i],nums[j]);
                    i++;
                    j++;
                }
                else{
                    i++;
                }
            }
            else{
                cnt=1;
                record=nums[i];
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
        return j;

        
    }
};
