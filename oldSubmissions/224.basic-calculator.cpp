class Solution {
public:
    int readparent(string &s ,int &i){
        int ans = 0;
        int temp =0;
        char op = '+';
        while(i<s.size()){
            //cout<<i<<" "<<ans<<endl;
            if(isdigit(s[i])){
                while(isdigit(s[i])){
                    temp = temp*10 + (s[i]-'0');
                    i++;
                }
                if(op=='+'){
                    ans+=temp;
                }
                else if(op=='-'){
                    ans-=temp;
                }
                temp = 0;
                op = 0;
            }
            else if(s[i]=='('){
                i++;
                temp = readparent(s,i);
                i++;
                if(op=='+'){
                    ans+=temp;
                }
                else if(op=='-'){
                    ans-=temp;
                }
                temp = 0;
                op = 0;
            }
            else if(s[i]==')'){
                break;
            }
            else if(s[i]=='+' || s[i]=='-'){
                op = s[i];
                i++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
    int calculate(string s) {
        int i = 0;
        return readparent(s,i);
    }
};
