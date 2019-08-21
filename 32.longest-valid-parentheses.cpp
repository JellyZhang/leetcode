struct Node{
    char first;
    int second;
    Node(char a,int b):first(a),second(b){};
};
class Solution {
public:
    //""
    //(())(((())))
    int longestValidParentheses(string s) {
        //int len = s.size();
        //if(len<2){
            //return 0;
        //}
        //stack<Node> sta;
        //int ans=0;
        //sta.push(Node(')',0));
        //for(int i=0;i<len;++i){
            //if(sta.empty() || s[i]=='('){
                //sta.push(Node(s[i],0));
            //}
            //else{
                //if(sta.top().first=='('){
                    //Node topNode=sta.top();
                    //sta.pop();
                    //sta.top().second+=topNode.second+1;
                //}
                //else{
                    //sta.push(Node(s[i],0));
                //}
            //}
        //}
        //while(!sta.empty()){
            //Node topNode=sta.top();
            //sta.pop();
            //ans=max(ans,topNode.second);
        //}
        //return 2*ans;
        
        int len = s.size();
        if(len<2){
            return 0;
        }
        vector<int> dp(len,0);
        //dp[i] -> maximum len that ends at i
        int ans=0;
        if(s[0]=='(' && s[1]==')'){
            dp[1]=2;
            ans=2;
        }
        for(int i=2;i<len;++i){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i]=dp[i-2]+2;
                    ans=max(ans,dp[i]);
                }
                else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='('){
                    if(i-dp[i-1]-2>=0){
                        dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];
                    }
                    else{
                        dp[i]=dp[i-1]+2;
                    }
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};
