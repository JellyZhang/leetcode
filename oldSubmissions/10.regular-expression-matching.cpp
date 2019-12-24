class Solution {
public:
    bool isMatch(string s, string p) {
        //if(p.empty())
            //return s.empty();
        //bool first_match = (!s.empty()) && (s[0]==p[0]||p[0]=='.');
        //if(p.size()>=2 && p[1]=='*'){
            //return (first_match && isMatch(s.substr(1),p))
                //|| isMatch(s,p.substr(2));
        //}
        //else{
            //return first_match && isMatch(s.substr(1),p.substr(1));
        //}
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,0));
        dp[s.size()][p.size()] = 1;
        for(int i = s.size();i>=0;i--){
            for(int j= p.size()-1;j>=0;j--){
                bool first_match = (i<s.size()) && (s[i]==p[j]||p[j]=='.');
                if(j+1<p.size() && p[j+1]=='*')
                    dp[i][j] = dp[i][j+2] || (first_match && dp[i+1][j]);
                else
                    dp[i][j] = first_match && dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};
