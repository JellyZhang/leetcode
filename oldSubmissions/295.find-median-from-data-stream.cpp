class MedianFinder {
private:
    priority_queue<int,vector<int>,greater<int>>q1;
    priority_queue<int,vector<int>,less<int>>q2;

public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(q2.empty() || num<q2.top()){
            q2.push(num);
        }
        else{
            q1.push(num);
        }
        if(q1.size()-q2.size()==2){
            int cur = q1.top();q1.pop();
            q2.push(cur);
        }
        else if(q2.size()-q1.size()==2){
            int cur = q2.top();q2.pop();
            q1.push(cur);
        }
        //cout<<"add"<<num<<" ";
        //if(!q1.empty())
            //cout<<q1.top();
        //else
            //cout<<"0";
        //if(!q2.empty())
            //cout<<q2.top();
        //else
            //cout<<"0";
        //cout<<endl;
    }
    
    double findMedian() {
        double sum = 0;
        if(q1.size()==q2.size()){
            if(!q1.empty())
                sum+=q1.top();
            if(!q2.empty())
                sum+=q2.top();
        }
        else if(q1.size()>q2.size()){
            return q1.top();
        }
        else{
            return q2.top();
        }
        return sum/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
