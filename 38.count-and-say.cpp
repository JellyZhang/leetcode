class Solution {
public:
    string numToString(int n){
        if(n==0){
            return "0";
        }
        string result = "";
        while(n){
            result.insert(0,1,'0'+n%10);
            n/=10;
        }
        return result;

    }
    string countAndSay(int n) {
        string str = "1";
        string str2 = "";
        int now;
        int nex;
        int cnt;
        for(int i=0;i<n-1;i++){
            now=0;
            nex=1;
            while(true){
                cnt=1;
                while(nex<str.size() && str[nex]==str[now]){
                    ++cnt;
                    ++nex;
                }
                str2.append(numToString(cnt));
                str2+=str[now];
                
                if(nex == str.size()){
                    break;
                }
                else{
                    now =nex;
                    nex = now+1;
                }
            }
            str=str2;
            str2.clear();
        }
        return str;
    }
};
