class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int ans=0;
        for(int n :nums){
            if(s.find(n)==s.end())continue;
            int pre = n-1;
            int nxt = n+1;
            while(s.find(pre)!=s.end())
                s.erase(pre--);
            while(s.find(nxt)!=s.end())
                s.erase(nxt++);
            ans = max(ans,nxt-pre-1);
        }
        return ans;
    }
};
