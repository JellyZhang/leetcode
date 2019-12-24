class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if(A.size()!=B.size())
            return -1;
        int ans = INT_MAX;
        int n = A.size();
        if(n==1){
            return 0;
        }
        int ra = 0;
        int rb = 0;
        for(int i=0;i<n;++i){
            if(A[i]!=A[0] && B[i]!=A[0]){
                ra = rb = INT_MAX;
                break;
            }
            if(A[i]!=A[0])ra++;
            if(B[i]!=A[0])rb++;
        }
        ans=min(ra,min(rb,ans));
        if(ans!=INT_MAX)
            return ans;
        //cout<<ans;
        ra = rb = 0;
        for(int i=0;i<n;++i){
            if(A[i]!=B[0] && B[i]!=B[0]){
                ra = rb = INT_MAX;
                break;
            }
            if(A[i]!=B[0])ra++;
            if(B[i]!=B[0])rb++;
        }
        ans=min(ra,min(rb,ans));
        //cout<<ans;
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
