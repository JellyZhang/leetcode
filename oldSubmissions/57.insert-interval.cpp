#include<algorithm>
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(newInterval.empty()){
            return intervals;
        }
        if(intervals.empty()){
            intervals.push_back(newInterval);
            return intervals;
        }
        int len = intervals.size();
        vector<int> sp(len);
        vector<int> ep(len);

        for(int i=0;i<len;++i){
            sp[i] = intervals[i][0];
            ep[i] = intervals[i][1];
        }
        if(newInterval[0]>ep[len-1]){
            intervals.push_back(newInterval);
            return intervals;
        }
        if(newInterval[1]<sp[0]){
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        int involve_f = std::lower_bound(ep.begin(),ep.end(),newInterval[0])-ep.begin();
        int involve_l = std::upper_bound(sp.begin(),sp.end(),newInterval[1])-sp.begin()-1;
        //cout<<involve_f<<" "<<involve_l;
        if(involve_l<involve_f){
            intervals.insert(intervals.begin()+involve_f,newInterval);
            return intervals;
        }
        int new_s = min(sp[involve_f],newInterval[0]);
        int new_e = max(ep[involve_l],newInterval[1]);
        intervals.erase(intervals.begin()+involve_f,intervals.begin()+involve_l+1);
        intervals.insert(intervals.begin()+involve_f,vector<int>({new_s,new_e}));
        return intervals;
    }
};
