/*
 * @lc app=leetcode id=1130 lang=cpp
 *
 * [1130] Minimum Cost Tree From Leaf Values
 */

// @lc code=start
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> available(arr.size(),1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,myComp> pq;
        for(int i=0;i<arr.size();++i){
            pq.push({i,arr[i]});
        }
        int ans=0;
        while(pq.size()>=2){
            auto cur = pq.top();pq.pop();
            int pos = cur.first;
            int i = pos-1;
            while(i>=0 && !available[i]){
                i--;
            }
            int j = pos+1;
            while(j<arr.size() && !available[j]){
                j++;
            }
            int temp;
            if(i>=0 && j<arr.size()){
                temp = min(arr[i],arr[j])*arr[pos];
            }
            else if(i>=0){
                temp = arr[i]*arr[pos];
            }
            else if(j<arr.size()){
                temp = arr[j]*arr[pos];
            }
            available[pos] = 0;
            //cout<<temp<<endl;
            ans += temp;
        }
        return ans;
        
    }
    struct myComp{
        bool operator()(pair<int,int>& x, pair<int,int>& y){
            return x.second>y.second;
        }
    };
};
// @lc code=end
