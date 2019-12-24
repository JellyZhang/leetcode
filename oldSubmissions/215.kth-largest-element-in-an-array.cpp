class Solution {
public:
    int findkth(vector<int>& nums,int start,int end,int k){
        int store = nums[start];
        int lo = start;
        int hi = end;
        while(lo<hi){
            while(lo<hi && nums[hi]>=store){
                hi--;
            }
            nums[lo] = nums[hi];
            while(lo<hi && nums[lo]<store){
                lo++;
            }
            nums[hi] = nums[lo];
        }
        nums[lo] = store;
        if(lo==k)
            return nums[lo];
        else if(lo<k){
            return findkth(nums,lo+1,end,k);
        }
        else
            return findkth(nums,start,lo-1,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        //return findkth(nums,0,nums.size()-1,nums.size()-k);
        priority_queue<int>pq;
        for(int i=0;i<k;++i)
            pq.push(-nums[i]);

        //cout<<k<<endl;
        for(int i=k;i<nums.size();++i){
            //cout<<"top is"<<-pq.top()<<endl;
            if(nums[i]>=-(pq.top())){
                pq.pop();
                pq.push(-nums[i]);
            }
        }
        return -pq.top();
    }
};
