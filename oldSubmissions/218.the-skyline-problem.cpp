class Solution {
public:
    struct Node{
        int endtime;
        int height;
        Node(int _x, int _y){
            endtime = _x;
            height = _y;
        }
        friend bool operator<(const Node& a, const Node& b){
            if(a.height==b.height)
                return a.endtime<b.endtime;
            else
                return a.height<b.height;
        }
    };
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //if(buildings.size()==0)
            //return {};
        //priority_queue<Node> q;
        //Node base(INT_MAX,0);
        //q.push(base);
        //buildings.push_back({INT_MAX,INT_MAX,0});
        //vector<vector<int>>ans;
        //for(auto& building:buildings){
            //int newstart = building[0];
            //int newend = building[1];
            //int newheight = building[2];
            ////clear dead
            //while(q.top().endtime<newstart){
                //Node cur = q.top();q.pop();
                //while(q.top().endtime<=cur.endtime){
                    //q.pop();
                //}
                //ans.push_back({cur.endtime,q.top().height});
            //}
            ////add new point
            //if(newheight>q.top().height){
                //if(!ans.empty() && newstart==ans.back()[0]){
                    //ans.pop_back();
                //}
                //ans.push_back({newstart,newheight});
            //}
            //Node newpoint(newend,newheight);
            //q.push(newpoint);
        //}
        //buildings.pop_back();
        //if(buildings.back()[1]==INT_MAX){
            //ans.push_back({INT_MAX,0});
        //}
        //return ans;
        vector<pair<int,int>>vec;
        for(auto& building:buildings){
            vec.push_back({building[0],-building[2]});
            vec.push_back({building[1],building[2]});
        }
        sort(begin(vec),end(vec));
        vector<vector<int>>ans;
        int pre = 0;
        multiset<int>heights;
        heights.insert(0);
        for(auto& v:vec){
            //update heights
            if(v.second<0){
                heights.insert(-v.second);
            }
            else{
                heights.erase(heights.find(v.second));
            }
            //hightest
            auto topHi = *heights.rbegin();
            //hightest point changed!
            if(topHi != pre){
                ans.push_back({v.first,topHi});
                pre = topHi;
            }
        }
        return ans;
    }
};
