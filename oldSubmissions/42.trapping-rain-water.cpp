class Solution {
public:
    int trap(vector<int>& height) {
        //int len = height.size();
        //if(len==0){
            //return 0;
        //}
        //vector<int> leftmax(len,0);
        //vector<int> rightmax(len,0);
        //int l_max=height[0];
        //for(int i=0;i<len;++i){
            //if(height[i]>l_max){
                //l_max=height[i];
            //}
            //leftmax[i]=l_max;
        //}
        //int r_max=height[len-1];
        //for(int i=len-1;i>=0;--i){
            //if(height[i]>r_max){
                //r_max=height[i];
            //}
            //rightmax[i]=r_max;
        //}
        //int ans=0;
        //for(int i=0;i<len;++i){
            //ans+=min(leftmax[i],rightmax[i])-height[i];
        //}
        //return ans;
        int len = height.size();
        if(len==0){
            return 0;
        }
        int i=0;
        int j=len-1;
        int leftmax=height[0];
        int rightmax=height[len-1];
        int ans=0;
        while(i<=j){
            if(height[i]<=height[j]){
                if(height[i]>leftmax){
                    leftmax=height[i];
                }
                else{
                    ans+=leftmax-height[i];
                }
                ++i;
            }
            else{
                if(height[j]>rightmax){
                    rightmax=height[j];
                }
                else{
                    ans+=rightmax-height[j];
                }
                --j;
            }
        }
        return ans;
    }
};
