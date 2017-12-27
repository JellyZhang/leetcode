#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        long long ans=0;
        int fushu=-1;
        int num=0;
        long long max_int=2147483647;
        for(int i=0;i<str.size();i++){
            if(str[i]==' '&&i==0)continue;
            if(str[i-1]==' '&&str[i]==' ')continue;
            if(str[i]==' '&&str[i-1]!=' ')break;
            if(str[i]=='-'){
                if(fushu==1||fushu==0)break;
                else if(i==0)fushu=1;
                else if(str[i-1]!=' ')break;
                else fushu=1;
            }else if(str[i]=='+'){
                if(fushu==1||fushu==0)break;
                else if(i==0)fushu=0;
                else if(str[i-1]!=' ')break;
                else fushu=0;
            }else if( (num=str[i]-'0') >=0 && num<=9 ){
                ans = ans*10LL+num;
                //cout<<ans<<endl;
                if(ans>2147483648LL)break;
            }else break;
        }
        //cout<<"fushu="<<fushu<<endl;
        if(ans==0)return 0;
        if(fushu==0||fushu==-1){
            if(ans>max_int)return max_int;
            else return (int)ans;
        }else {
            if(ans>max_int+1)return -max_int-1;
            else return (int)(-ans);
        }
        return 0;
    }
};
int main(){
    Solution S;
    //cout<<S.myAtoi("  bb")<<endl;
    //cout<<S.myAtoi("  11111")<<endl;
    //cout<<S.myAtoi("2147483647")<<endl;
    //cout<<S.myAtoi("2147483648")<<endl;
    //cout<<S.myAtoi("   -2147483648")<<endl;
    cout<<S.myAtoi("    +0 123")<<endl;

    return 0;
}
