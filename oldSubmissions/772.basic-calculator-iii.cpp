typedef long long ll;

class Solution {
public:
    //ll readdig(string&s ,int &index){
        //while(s[index]==' '){
            //index++;
        //}
        //ll ans = 0;
        //if(s[index]=='('){
            //index++;
            //ans = readexpr(s,index);
        //}
        //else{
            //while(isdigit(s[index])){
                //ans = 10*ans + (s[index]-'0');
                //index++;
            //}
        //}
        ////cout<<"getdig "<<ans<<endl;
        //return ans;
    //}
    //char readop(string&s, int &index){
        //while(index<s.size() && s[index]!=')'&& s[index]==' '){
            //index++;
        //}
        //if(index==s.size())
            //return '#';
        //return s[index++];
    //}
    //ll readonce(string& s,int& index){
        //ll ans = readdig(s,index);
        //char op = readop(s,index);
        //while(index<s.size() && (op=='*' || op=='/')){
            //int temp = readdig(s,index);
            //if(op=='*')
                //ans*=temp;
            //else
                //ans/=temp;
            //op = readop(s,index);
        //}
        ////cout<<"getonce "<<ans<<endl;
        //return ans;
    //}
    //ll readexpr(string& s,int &index) {
        //ll ans = 0;
        //char op = '+';
        //while(index<s.size() && op!=')'){
            //int temp = readonce(s,index);
            //if(op=='+')
                //ans+=temp;
            //else
                //ans-=temp;
            //index--;
            //op = readop(s,index);
            ////cout<<"getop "<<op<<endl;
        //}
        ////cout<<"getexpr "<<ans<<endl;
        //return ans;
    //}
    ll parseNum(string& s, int &index){
        ll ans = 0;
        while(index<s.size() && isdigit(s[index])){
            ans = 10*ans + (s[index++] - '0');
        }
        return ans;
    }
    int parseExpr(string& s, int &index){
        vector<ll>nums;
        char op = '+';
        while(index<s.size() && op!=')'){
            if(s[index]==' '){
                index++;
                continue;
            }
            ll temp;
            if(s[index]=='(')
                temp = parseExpr(s,++index);
            else
                temp = parseNum(s,index);
            switch(op){
                case '+':
                    nums.push_back(temp);
                    break;
                case '-':
                    nums.push_back(-temp);
                    break;
                case '*':
                    nums.back()*=temp;
                    break;
                case '/':
                    nums.back()/=temp;
                    break;
            }
            while(index<s.size() && s[index]==' ')
                index++;
            if(index<s.size()){
                op = s[index++];
            }
        }
        return accumulate(nums.begin(),nums.end(),0);
    }
    int calculate(string s) {
        int index = 0;
        return parseExpr(s,index);
    }
};
