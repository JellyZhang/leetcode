class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>> hashs;
    unordered_map<string,vector<int>>times;
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        //cout<<"set "<<key<<"time "<<timestamp<<" ";
        hashs[key][timestamp] = value;
        times[key].push_back(timestamp);
        return;
    }
    
    string get(string key, int timestamp) {
        //cout<<"get "<<key<<"time "<<timestamp<<" ";
        
        auto & time = times[key];
        if(time.size()==0)
            return "";
        int index = lower_bound(time.begin(),time.end(),timestamp)-time.begin();
        //cout<<"find time "<<index<<" ";
        if(index<time.size() && time[index]==timestamp){
            return hashs[key][time[index]];
        }
        else if(index!=0){
            return hashs[key][time[index-1]];
        }
        return "";
    
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
