class Solution {
public:
    struct Node{
        bool in;
        int time;
        Node(bool _in,int _time):in(_in),time(_time){}
        bool friend operator<(const Node &x, const Node &y){
            if(x.time!=y.time)
                return x.time>y.time;
            else
                return x.in;
        }
    };
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<Node>q;
        for(int i=0;i<intervals.size();++i){
            q.push(Node(true,intervals[i][0]));
            q.push(Node(false,intervals[i][1]));
        }
        int ans = 0;
        int cnt = 0;
        while(!q.empty()){
            Node cur = q.top();q.pop();
            if(cur.in){
                cnt++;
                if(cnt>ans)
                    ans=cnt;
            }
            else{
                cnt--;
            }
        }
        return ans;
    }
};
