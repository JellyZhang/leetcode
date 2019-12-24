class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()<=1)
            return true;
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            while(i<=j && !(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9'))
                ++i;
            while(i<=j && !(s[j]>='a'&&s[j]<='z'||s[j]>='A'&&s[j]<='Z'||s[j]>='0'&&s[j]<='9'))
                --j;
            if(i<=j){
                if(s[i]>='a')
                    s[i]=s[i]-'a'+'A';
                if(s[j]>='a')
                    s[j]=s[j]-'a'+'A';
                if(s[i]!=s[j])
                    return false;
                else{
                    ++i;
                    --j;
                }

            }
        }
        return true;
    }
};
