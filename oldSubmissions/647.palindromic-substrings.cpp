/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        int ans = 0;
        for(int i=0;i<s.size();++i){
            dp[i][0] = 1;
        }
        for(int i=0;i+1<s.size();++i){
            dp[i][1] = (s[i]==s[i+1])?(1):(0);
        }
        for(int i=s.size()-1;i>=0;--i){
            for(int j=2;i+j<s.size();++j){
                dp[i][j] = dp[i+1][j-2] &&  ((s[i]==s[i+j])?(1):(0));
            }
        }
        for(int i=0;i<s.size();++i){
            for(int j=0;i+j<s.size();++j){
                if(dp[i][j]){
                    ans++;
                    //cout<<i<<" "<<j<<endl;
                }
            }
        }
        return ans;
        
    }
};
// @lc code=end
