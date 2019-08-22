class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m =matrix.size();
        if(!m){
            return 0;
        }
        int n =matrix[0].size();
        if(!n){
            return 0;
        }
        vector<int> dp(n,0);
        int ans=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]=='1'){
                    dp[j]=dp[j]+1;
                }
                else{
                    dp[j]=0;
                }
            }
            ans=max(ans,maximunAreaOfBars(dp));
        }
        return ans;
    }
    int maximunAreaOfBars(vector<int> heights){
        if(heights.size()==0){
            return 0;
        }
        heights.push_back(0);
        int len = heights.size();
        stack<int> sta;
        int ans=0;
        for(int i=0;i<len;++i){
            if(sta.empty() || heights[i]>=heights[sta.top()]){
                sta.push(i);
            }
            else{
                int tp = sta.top();
                sta.pop();
                int res;
                if(sta.empty()){
                    res = heights[tp]*(i);
                }
                else{
                    res = heights[tp]*(i-sta.top()-1);
                }
                ans=max(ans,res);
                --i;
            }
        }
        return ans;
    }
};
