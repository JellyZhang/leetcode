class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int>candy_left(len,1);
        vector<int>candy_right(len,1);
        for(int i=1;i<len;++i){
            if(ratings[i]>ratings[i-1]){
                candy_left[i]=candy_left[i-1]+1;
            }
        }
        for(int i=len-2;i>=0;--i){
            if(ratings[i]>ratings[i+1]){
                candy_right[i]=candy_right[i+1]+1;
            }
        }
        int ans=0;
        for(int i=0;i<len;++i){
            ans+=max(candy_left[i],candy_right[i]);
        }
        return ans;

    }
};
