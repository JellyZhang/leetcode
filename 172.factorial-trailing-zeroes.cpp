class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long long temp = 5;
        while(temp<=n){
            //cout<<n/temp<<" ";
            ans += n/temp;
            temp*=5;
        }
        return ans;
    }
};
