class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return 0;
        auto minmax = minmax_element(nums.begin(),nums.end());
        int low = *minmax.first;
        int high = *minmax.second;
        int gap = max((high-low)/(n-1),1);
        
        int m = (high - low)/gap +1;
        vector<int>maxelement(m,INT_MIN);
        vector<int>minelement(m,INT_MAX);
        for(int i:nums){
            int k = (i-low)/gap;
            if(i<minelement[k]){
                minelement[k] = i;
            }
            if(i>maxelement[k]){
                maxelement[k] = i;
            }
        }
        int p = 0;
        int ans = maxelement[0]-minelement[0];
        int q;
        while(p+1<m){
            q = p+1;
            while(q<m && minelement[q]==INT_MAX){
                q++;
            }
            if(q==m)
                break;
            if(minelement[q]-maxelement[p]>ans){
                ans = minelement[q]-maxelement[p];
            }
            p = q;
        }
        return ans;
    }
};
