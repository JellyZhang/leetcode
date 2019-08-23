class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0){
            return {0};
        }
        vector<int>ans = {0,1};
        for(int i=2;i<=n;++i){
            int len = ans.size();
            for(int j=len-1;j>=0;--j){
                ans.push_back(ans[j]+pow(2,i-1));
            }
        }
        return ans;
        
    }
};
