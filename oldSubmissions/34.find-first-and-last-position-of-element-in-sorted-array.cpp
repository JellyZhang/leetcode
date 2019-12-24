class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.clear();
        int p=0;
        int q=nums.size()-1;
        int mid = (p+q)>>1;
        while(p<=q){
            //cout<<p<<" "<<q<<endl;
            mid = (p+q)>>1;
            if(nums.at(mid)<target){
                p=mid+1;
            }
            else if(nums.at(mid)>= target){
                q=mid-1;
            }
        }
        //cout<<p<<",";
        if(p<nums.size() && nums.at(p)==target){
            ans.push_back(p);
        }
        else{
            ans.push_back(-1);
        }
        p=0;
        q=nums.size()-1;
        mid = (p+q)>>1;
        while(p<=q){
//            cout<<p<<" "<<q<<endl;
            mid = (p+q)>>1;
            if(nums.at(mid)<=target){
                p=mid+1;
            }
            else if(nums.at(mid)> target){
                q=mid-1;
            }
        }
       // cout<<p-1<<";";
        if(p-1>=0 && nums.at(p-1)==target){
            ans.push_back(p-1);
        }
        else{
            ans.push_back(-1);
        }
        return ans;
        
    }
};
