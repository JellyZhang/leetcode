class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator it,it2;
        vector<int> result;
        for(it = nums.begin();it!=nums.end();it++){
            int m=*it;
            for(it2=it+1;it2!=nums.end();it2++){
                if(*it2+m==target){
                    result.push_back(it-nums.begin());
                    result.push_back(it2-nums.begin());
                    return result;
                }
            }
        }
    }
};
