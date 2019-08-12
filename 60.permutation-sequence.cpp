class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> bangs(10);
        int temp =1;
        for(int i=1;i<=9;++i){
            temp*=i;
            bangs[i]=temp;
        }
        //bangs[n] = n!
        for(int i=1;i<=n;++i){
            ans+='0'+i;
        }
        k--;
        for(int i=0;i<n-1;++i){
            //n times
            int index = k/bangs[n-i-1];
            std::swap(ans[i],ans[i+index]);
            sort(ans.begin()+i+1,ans.end());
            //if use a string "123456789" with erase and push_back, can avoid sort
            k= k%bangs[n-i-1];
        }
        return ans; 
    }
};
