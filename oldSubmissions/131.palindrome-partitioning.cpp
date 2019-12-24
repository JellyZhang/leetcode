class Solution {
public:
    bool ispalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    void dfs(string &s,int start,vector<string>& selected,vector<vector<string>>&ans){
        if(start==s.size()){
            ans.push_back(selected);
            return;
        }
        for(int i=start;i<s.size();++i){
            if(ispalindrome(s,start,i)){
                selected.push_back(s.substr(start,i-start+1));
                dfs(s,i+1,selected,ans);
                selected.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        if(s.size()==0)
            return {};
        vector<vector<string>>ans;
        vector<string>selected;
        dfs(s,0,selected,ans);
        return ans;
    }
};
