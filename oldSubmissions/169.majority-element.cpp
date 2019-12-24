class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //return findkth(nums,0,nums.size()-1,nums.size()/2);
        unordered_map<int,int>hash;
        int ans = -1;
        for(int i=0;i<nums.size();++i){
            hash[nums[i]]++;
            if(hash[nums[i]]>nums.size()/2){
                ans = nums[i];
                break;
            }
        }
        //return ans;
        return votealgo(nums);

    }
    int votealgo(vector<int>&nums){
        int candidate;
        int count = 0;
        for(int i=0;i<nums.size();++i){
            if(count==0)
                candidate = nums[i];
            if(nums[i]==candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
    int findkth(vector<int>&nums, int start, int end, int k){ // k = 0,1,2,... 
        //cout<<start<<" "<<end<<" "<<k<<endl;
        int temp = nums[start];
        int lo = start;
        int hi = end;
        while(lo<hi){
            //cout<<"!";
            while(nums[hi]>=temp && lo<hi)
                hi--;
            nums[lo] = nums[hi];
            while(nums[lo]<=temp && lo<hi)
                lo++;
            nums[hi]=nums[lo];
        }
        nums[lo]=temp;
        if(lo==k){
            return nums[lo];
        }
        else if(lo>k){
            return findkth(nums,start,lo-1,k);
        }
        else{
            return findkth(nums,lo+1,end,k);
        }
    }
};
