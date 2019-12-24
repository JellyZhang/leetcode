class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();++i){
            m[nums[i]]++;
        }
        int ans=0;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second==1){
                ans=it->first;
            }
        }
        return ans;
    }
};
