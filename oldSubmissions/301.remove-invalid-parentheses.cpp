class Solution {
public:
    void dfs(string &s,int cnt_opening,int cnt_closing,int index,set<string>&ans,string &selected){
        //cout<<cnt_opening<<" "<<cnt_closing<<" "<<selected<<" "<<index<<endl;
        if(index==s.size()){
            if(cnt_opening==0 && cnt_closing==0){
                ans.insert(selected);
            }
            return;
        }
        if(s[index]=='('){
            if(cnt_opening>0){
                selected+='(';
                dfs(s,cnt_opening-1,cnt_closing,index+1,ans,selected);
                selected.pop_back();
            }
            dfs(s,cnt_opening,cnt_closing,index+1,ans,selected);
        }
        else if(s[index]==')'){
            if(cnt_closing>0 && cnt_opening<cnt_closing){
                selected+=')';
                dfs(s,cnt_opening,cnt_closing-1,index+1,ans,selected);
                selected.pop_back();
            }
            dfs(s,cnt_opening,cnt_closing,index+1,ans,selected);
        }
        else{
            selected+=s[index];
            dfs(s,cnt_opening,cnt_closing,index+1,ans,selected);
            selected.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        if(s.size()==0)
            return {""};
        stack<char>stk;
        int cnt_opening = 0;
        int cnt_closing = 0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                stk.push(s[i]);
                cnt_opening++;
            }
            else if(s[i]==')'){
                cnt_closing++;
                if(!stk.empty() && stk.top()=='('){
                    stk.pop();
                }
                else
                    stk.push(s[i]);
            }
        }
        while(!stk.empty()){
            if(stk.top()=='('){
                cnt_opening--;
            }
            else{
                cnt_closing--;
            }
            stk.pop();
        }
        set<string> ans;
        string selected = "";
        dfs(s,cnt_opening,cnt_closing,0,ans,selected);
        vector<string> rtn(ans.begin(),ans.end());
        return rtn;
        
    }

};
