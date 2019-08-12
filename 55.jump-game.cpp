class Solution {
public:
    bool canJump(vector<int>& nums) {
        int now = 0;
        int len = nums.size();
        if(len==0){
            return false;
        }
        if(len==1){
            return true;
        }
        while(true){
            int max = -1;
            int pos = -1;
            for(int i=1;i<=nums[now];++i){
                int nxt = now+i;
                if(nxt>=len-1){
                    return true;
                }
                if(max==-1||(nums[nxt]+i>=max)){
                    max = nums[nxt]+i;
                    pos = nxt;
                }
            }
            if(max == -1){
                return false;
            }
            else{
                now = pos;
            }
        }
    }
};
