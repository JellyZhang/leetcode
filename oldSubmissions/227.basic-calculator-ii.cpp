class Solution {
public:
    //int readdig(string&s ,int &index){
        //while(s[index]==' '){
            //index++;
        //}
        //int ans = 0;
        //while(isdigit(s[index])){
            //ans = 10*ans + (s[index]-'0');
            //index++;
        //}
        //return ans;
    //}
    //char readop(string&s, int &index){
        //while(index<s.size() && s[index]==' '){
            //index++;
        //}
        //if(index==s.size())
            //return '#';
        //return s[index++];
    //}
    //int readonce(string& s,int& index){
        //int ans = readdig(s,index);
        //char op = readop(s,index);
        //while(index<s.size() && (op=='*' || op=='/')){
            //int temp = readdig(s,index);
            //if(op=='*')
                //ans*=temp;
            //else
                //ans/=temp;
            //op = readop(s,index);
        //}
        //return ans;
    //}
    //int calculate(string s) {
        //int index = 0;
        //int ans = 0;
        //char op = '+';
        //while(index<s.size()){
            //int temp = readonce(s,index);
            //if(op=='+')
                //ans+=temp;
            //else
                //ans-=temp;
            //index--;
            //op = readop(s,index);
        //}
        //return ans;
    //}
    int parseNum(string& s, int &index){
        int ans = 0;
        while(index<s.size() && isdigit(s[index])){
            ans = 10*ans + (s[index++] - '0');
        }
        return ans;
    }
    int calculate(string s){
        int index = 0;
        vector<int>nums;
        char op = '+';
        while(index<s.size()){
            if(s[index]==' '){
                index++;
                continue;
            }
            int temp = parseNum(s,index);
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
};
