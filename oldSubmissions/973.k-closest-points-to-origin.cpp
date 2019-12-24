struct Node{
    int x;
    int y;
    Node(int _x, int _y):x(_x),y(_y){}
    friend bool operator<(const Node &a, const Node &b){
        return (a.x*a.x+a.y*a.y)>(b.x*b.x+b.y*b.y);
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //priority_queue<Node> pq;
        //for(int i=0;i<points.size();++i){
            //Node temp(points[i][0],points[i][1]);
            //pq.push(temp);
        //}
        //vector<vector<int>>ans;
        //for(int i=0;i<K;++i){
            //if(pq.empty())
                //break;
            //Node temp = pq.top();pq.pop();
            //ans.push_back({temp.x,temp.y});
        //}
        //return ans;
        if(K>=points.size())
            return points;
        //findkth(points,0,points.size()-1,K);
        //vector<vector<int>> ans(points.begin(),points.begin()+K);
        //sort(ans.begin(),ans.end());
        sort(points.begin(),points.end(),[](const vector<int> &a,const vector<int> &b){
                return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];
                });
        vector<vector<int>> ans(points.begin(),points.begin()+K);
        return ans;
    }
    void findkth(vector<vector<int>>& points, int start, int end, int k){
        int lo = start;
        int hi = end;
        vector<int> store = points[start];
        int temp = getdis(points[start]);
        while(lo<hi){
            while(lo<hi && getdis(points[hi])>=temp)
                hi--;
            points[lo]=points[hi];
            while(lo<hi && getdis(points[lo])<=temp)
                lo++;
            points[hi]=points[lo];
        }
        points[lo] = store;
        if(lo==k){
            return;
        }
        else if(lo<k){
            findkth(points,lo+1,end,k);
        }
        else{
            findkth(points,start,lo-1,k);
        }
    }
    int getdis(vector<int>& point){
        return point[0]*point[0]+point[1]*point[1];
    }
};
