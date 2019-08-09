class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = 0;
        int ans = 0;
        int sum = 0;
        bool increasing = true;
        height.push_back(0);
        height.insert(height.begin(),0);
        for(int i =1;i<height.size();++i){
//            cout<<sum<<","<<ans<<".";
            cout<<height[i]<<",";
            if(increasing && height[i]<height[i-1]){
                if(height[i-1]<height[leftMax]){
                    sum-=(i-1-leftMax)*(height[leftMax]-height[i-1]);
                    int temp = leftMax+1;
                    while(height[temp]>height[i-1]){
                        sum+=height[temp]-height[i-1];
                        ++temp;
                    }
                }
                ans +=sum;
                sum=0;
                leftMax = i-1;
                increasing = false;
            }
            if(height[i]<height[leftMax]){
                sum+=height[leftMax]-height[i];
            }
            if(!increasing && height[i]>height[i-1]){
                increasing = true;
            }
        } 
        return ans;
        
    }
};
