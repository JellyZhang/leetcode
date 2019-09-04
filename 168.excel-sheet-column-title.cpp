class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n){
            //cout<<n<<" ";
            int left = n%26;
            if(!left)
                left = 26;
            ans+='A'+left-1;
            n  = (n - left)/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
