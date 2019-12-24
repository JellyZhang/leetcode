#include <vector>
using namespace std;    

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(0==nums.size()){
            return;
        }
        int n =nums.size();
        int p = n-1;
        while(p-1>=0 && nums.at(p-1)>= nums.at(p)){
            --p;
        }
        if(p==0){
            //reverse
            for(int i=0;i<n/2;i++){
                int temp = nums.at(i);
                nums.at(i) = nums.at(n-1-i);
                nums.at(n-1-i) = temp;
            }
            return;
        }
        // now nums(p-1)< nums(p) and p!=0
        int hi = n-1;
        int lo = p;
        int mid = (hi+lo)>>1;
        int pos=lo;
        int target = nums.at(p-1);
        while(lo<hi){
            mid = (hi+lo+1)/2;
            if(nums.at(mid) > target){
                lo = mid;
                pos = lo;
            }
            else{
                hi = mid-1;
                pos=hi;
            }
        }
        //cout<<nums.at(p-1)<<" "<<nums.at(pos);
        int temp = nums.at(p-1);
        nums.at(p-1) = nums.at(pos);
        nums.at(pos) = temp;
        sort(nums.begin()+p,nums.end());
        return;
    }
};
