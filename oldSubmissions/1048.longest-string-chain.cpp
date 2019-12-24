/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string a,string b){
                return a.size()<b.size();
                });
        vector<int> dp(words.size(),0);
        for(int i=0;i<words.size();++i){
            int tmp_max = 0;
            for(int j=0;j<i;++j){
                if(isPreDecessor(words[j],words[i]) && dp[j]>tmp_max)
                    tmp_max = dp[j];
            }
            dp[i] = tmp_max+1;
        }
        int ans = 0;
        for(int i=0;i<dp.size();++i){
            //cout<<words[i]<<" ";
            //cout<<dp[i]<<" ";
            ans = max(ans,dp[i]);
        }
        return ans;
    }
    bool isPreDecessor(const string& str1, const string& str2){
        if(str1.size()+1!=str2.size())
            return false;
        int i =0;
        int j =0;
        int flag = 1;
        while(i<str1.size()){
            if(str1[i]!=str2[j]){
                flag--;
                if(flag<0)
                    return false;
                j++;
                continue;
            }
            i++;
            j++;
        }
        return true;
    }
};
// @lc code=end
