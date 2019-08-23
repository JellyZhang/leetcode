#include <string>
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4 || s.size()>12)
            return {};
        vector<string> ans;
        for(int a=1;a<=3;++a)
            for(int b=1;b<=3;++b)
                for(int c=1;c<=3;++c)
                    for(int d=1;d<=3;++d){
                        if(a+b+c+d==s.size()){
                            int na = simpleatoi(s.substr(0,a));
                            int nb = simpleatoi(s.substr(a,b));
                            int nc = simpleatoi(s.substr(a+b,c));
                            int nd = simpleatoi(s.substr(a+b+c,d));
                            if(na<=255 && nb<=255 && nc<=255 && nd<=255){
                                string tmp = simpleitos(na)+'.'+simpleitos(nb)+'.'+simpleitos(nc)+'.'+simpleitos(nd);
                                if(tmp.size()==s.size()+3){
                                    ans.push_back(tmp);
                                }
                            }
                        }
                    }
        return ans;
    }
    int simpleatoi(string s){
        int times=1;
        int ans=0;
        for(int i=s.size()-1;i>=0;--i){
            ans+=(s[i]-'0')*times;
            times*=10;
        }
        return ans;
    }
    string simpleitos(int a){
        if(a==0){
            return "0";
        }
        string ans="";
        while(a){
            ans.insert(ans.begin(),'0'+a%10);
            a/=10;
        }
        return ans;
    }
};
