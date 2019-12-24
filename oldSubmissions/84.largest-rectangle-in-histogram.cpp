class Solution {
public:
    //[1,1]
    int largestRectangleArea(vector<int>& heights) {
        //int len = heights.size();
        //if(len==0){
            //return 0;
        //}
        //vector<int> firstlowleft(len,0);
        //vector<int> firstlowright(len,0);
        //stack<int> sta;
        //for(int i=0;i<len;++i){
            //while(!sta.empty() && heights[sta.top()]>=heights[i]){ //! >=
                //sta.pop();
            //}
            //if(sta.empty()){
                //firstlowleft[i]=-1;
            //}
            //else{
                //firstlowleft[i]=sta.top();
            //}
            //sta.push(i);
        //}
        //while(!sta.empty()){
            //sta.pop();
        //}
        //for(int i=len-1;i>=0;--i){
            //while(!sta.empty() && heights[sta.top()]>=heights[i]){
                //sta.pop();
            //}
            //if(sta.empty()){
                //firstlowright[i]=len;
            //}
            //else{
                //firstlowright[i]=sta.top();
            //}
            //sta.push(i);
        //}
        //int ans=0;
        //for(int i=0;i<len;++i){
            //ans=max(ans,heights[i]*(firstlowright[i]-firstlowleft[i]-1));
        //}
        //return ans;
        
        if(heights.size()==0){
            return 0;
        }
        heights.push_back(0);
        int len = heights.size();
        stack<int> sta;
        int ans=0;
        int i=0;
        while(i<len){
            if(sta.empty() || heights[i]>=heights[sta.top()]){
                sta.push(i++);
            }
            else{
                int height = heights[sta.top()];
                sta.pop();
                int j = (sta.empty())?-1:sta.top();
                ans=max(ans,height*(i-j-1));
            }
        }
        return ans;
    }
};
