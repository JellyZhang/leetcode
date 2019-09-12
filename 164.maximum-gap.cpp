class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<=1){
            return 0;
        }
        int lowest = min(nums[0],nums[1]);
        int highest = max(nums[0],nums[1]);
        int lo = lowest;
        int hi = highest;
        for(int i=2;i<nums.size();++i){
            cout<<lo<<" "<<hi<<" "<<lowest<<" "<<highest<<endl;
            cout<<nums[i]<<endl;
            if(nums[i]>highest){
                if(nums[i]-highest>hi-lo){
                    lo = highest;
                    highest = nums[i];
                    hi = nums[i];
                }
                else{
                    highest = nums[i];
                }
            }
            else if(nums[i]<lowest){
                if(lowest-nums[i]>hi-lo){
                    hi = lowest;
                    lowest = nums[i];
                    lo = lowest;
                }
                else{
                    lowest = nums[i];
                }
            }
            else if(nums[i]>lo && nums[i]<hi){
                if(nums[i]-lo > hi - nums[i]){
                    hi = nums[i];
                }
                else{
                    lo = nums[i];
                }
            }
        }

        //sort(nums.begin(),nums.end());
        //for(int i=0;i<nums.size();++i){
            //cout<<nums[i]<<" ";
        //}
        //cout<<endl;
        //cout<<hi<<" "<<lo<<" "<<highest<<" "<<lowest;
        return hi-lo;
    }
};
