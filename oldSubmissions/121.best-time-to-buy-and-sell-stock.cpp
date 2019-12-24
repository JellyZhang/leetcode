class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int min_before = prices[0];
        int ans=0;
        for(int i=1;i<prices.size();++i){
            if(prices[i]<min_before){
                min_before=prices[i];
            }
            else if(prices[i]-min_before>ans){
                ans = prices[i]-min_before;
            }
        }
        return ans;
        
    }
};
