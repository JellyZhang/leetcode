class Solution {
public:
    string decodeString(string s) {
        int index=0;
        stack<int>multi;
        stack<string>str;
        str.push("");
        string ans = "";
        while(index<s.size()){
            if(s[index]>='0' && s[index]<='9'){
                int cnt=0;
                while(s[index]>='0' && s[index]<='9'){
                    cnt = cnt*10+s[index]-'0';
                    index++;
                }
                multi.push(cnt);
                //cout<<"push"<<cnt<<" ";
                index++;
                string temp = "";
                while(s[index]>='a' && s[index]<='z'){
                    temp+=s[index];
                    index++;
                }
                str.push(temp);
                //cout<<"push"<<temp<<" ";
            }
            else if(s[index]==']'){
                int temp_cnt = multi.top();multi.pop();
                string temp_str = str.top();str.pop();
                string temp = "";
                while(temp_cnt--){
                    temp+=temp_str;
                }
                //cout<<"make"<<temp<<" ";
                string cur = str.top();str.pop();
                cur+=temp;
                str.push(cur);
                index++;
            }
            else{
                string cur = str.top();str.pop();
                cur+=s[index];
                str.push(cur);
                index++;
            }
        }
        return str.top();
    }
};
