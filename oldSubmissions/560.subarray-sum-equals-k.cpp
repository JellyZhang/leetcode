class Solution {
public:
    struct Node{
        int pos;
        int val;
        Node(int _pos, int _val):pos(_pos),val(_val){}
    };
    bool check(vector<Node>& nodes,int start, int end){
        vector<int> temp;
        for(int i=start;i<=end;++i){
            temp.push_back(nodes[i].pos);
        }
        sort(temp.begin(),temp.end());
        if(temp.back()-temp.front()+1==temp.size())
            return true;
        return false;
    }
    int subarraySum(vector<int>& nums, int k) {
        //vector<int> sums(nums.size());
        //int temp_sum = 0;
        //for(int i=0;i<nums.size();++i){
            //sums[i] = temp_sum+nums[i];
            //temp_sum = sums[i];
        //}
        //int ans=0;
        //for(int i=0;i<nums.size();++i){
            //for(int j=i;j<nums.size();++j){
                //if(sums[j]-sums[i]+nums[i]==k)
                    //ans++;
            //}
        //}
        //return ans;
        //
        if(nums.size()==0){
            return 0;
        }
        vector<Node>nodes;
        for(int i=0;i<nums.size();++i){
            nodes.push_back(Node(i,nums[i]));
        }
        sort(nodes.begin(),nodes.end(),[](const Node& x,const Node& y){
                return x.val<y.val;
                });
        int p = 0;
        int q = 0;
        int cur = nodes[0].val;
        int ans = 0;
        for(int i=0;i<nodes.size();++i){
            cout<<nodes[i].val<<" ";
        }
        cout<<endl;
        for(int i=0;i<nodes.size();++i){
            cout<<nodes[i].pos<<" ";
        }
        cout<<endl;
        while(p<nodes.size()){
            cout<<p<<" "<<q<<" "<<cur<<endl;
            if(cur == k){
                if(check(nodes,p,q)){
                    ans++;
                }
                if(q!=nodes.size()-1){
                    q++;
                    cur+=nodes[q].val;
                }
                else{
                    cur-=nodes[p].val;
                    p++;
                }
            }
            else if(cur>k || cur<k && q==nodes.size()-1){
                cur-=nodes[p].val;
                p++;
            }
            else{
                q++;
                cur+=nodes[q].val;
            }
        }
        return ans;
    }
};
