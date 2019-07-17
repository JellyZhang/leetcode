class Solution {
public:
    bool isValid(string s) {
        stack<char>sta;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' ||s[i]=='['|| s[i]=='{')sta.push(s[i]);
            else {
                if(sta.empty())return false;
                if(s[i]==')'){
                    if(sta.top()!='(')return false;
                }
                else if(s[i]==']'){
                    if(sta.top()!='[')return false;
                }
                else if(s[i]=='}'){
                    if(sta.top()!='{')return false;
                }
                sta.pop();
            }
        }
        if(!sta.empty())return false;
        return true;
    }
};
