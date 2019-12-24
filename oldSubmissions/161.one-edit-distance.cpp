class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size()==t.size()){
            int dif = 0;
            for(int i=0;i<s.size();++i){
                if(s[i]!=t[i])
                    dif++;
            }
            if(dif==1)
                return true;
            else
                return false;
        }
        else if(s.size()<t.size()){
            return isOneEditDistance(t,s);
        }
        else{
            if(s.size()-t.size()>1)
                return false;
            int q=0;
            int flag=1;
            for(int p=0;p<t.size();++p){
                if(t[p]!=s[q]){
                    if(!flag)
                        return false;
                    flag--;
                    p--;
                }
                q++;
            }
            return true;
        }
        return false;
    }
};
