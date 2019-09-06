#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
//class Solution {
//public:
    //vector<vector<int>> threeSum(vector<int>& nums) {
        //vector<vector<int> > ans;
        //sort(nums.begin(),nums.end());
        //vector<int>::iterator it1,it2,it3;
        //for(it3=begin(nums);it3!=end(nums);it3++){
            //if(it3>nums.begin() && *(it3)==*(it3-1))continue;
            //if(it3==end(nums))break;
            //if(*it3>0)break;
            //int target=0-*it3;
            ////cout<<"target:"<<target<<endl;
            //it1=it3+1;
            //it2=nums.end()-1;
            //while(it1<it2){
                //if(*it1+*it2>target)it2--;
                //else if(*it1+*it2<target)it1++;
                //else {
                        //vector<int> temp{*it1,*it2,*it3};
                        //ans.push_back(temp);
                        //it1++;
                        //it2--;
                        //while(*it1==*(it1-1))it1++;
                        //while(*it2==*(it2+1))it2--;
                //}
                ////cout<<"!"<<endl;
               //// cout<<*it1<<"    "<<*it2<<endl;
            //}
        //}
        //return ans;
    //}
//};
struct Node{
    int x;
    int y;
    Node(int a,int b){
        x=a;
        y=b;
    }
    friend bool operator<(const Node &a, const Node &b){
        if(a.x!=b.x){
            return b.x<a.x;// a b 交换位置的条件
        }
        else{
            return a.y<b.y;
        }
    }

};
struct cmp{
    bool operator()(const Node &a ,const Node &b){
        if(a.x!=b.x){
            return b.x<a.x;// a b 交换位置的条件
        }
        else{
            return a.y<b.y;
        }
    }
};
int main(){

    //std::string a = "abc";
    //std::vector<std::string> strs;
    //strs.push_back("aaa");
    //strs.push_back("bbb");
//    for (auto i:strs){
//        std::cout<<i;
//    }
    //Solution s;
    //vector<int> nums = {2,-2,4};
    //vector<vector<int>> t = s.threeSum(nums);
    //cout<<t.size();
    //
    //priority_queue<Node,vector<Node>,cmp> q;
    //q.push(Node(1,2));
    //q.push(Node(2,2));
    //q.push(Node(1,1));
    //q.push(Node(2,1));
    //q.push(Node(1,3));
    //while(!q.empty()){
        //Node top = q.top();
        //cout<<top.x<<" "<<top.y<<endl;
        //q.pop();
    //}
    //vector<int> v={1,2,2,3,4,5,6};
    //cout<<upper_bound(begin(v),end(v),2)-v.begin()<<endl;
    //cout<<upper_bound(begin(v),end(v),6)-v.begin()<<endl;
    //cout<<upper_bound(begin(v),end(v),7)-v.begin()<<endl;
    //vector<int> v={6,5,4,3,2,2,1};
    //cout<<upper_bound(end(v),begin(v),2)-v.begin()<<endl;
    //cout<<upper_bound(end(v),begin(v),6)-v.begin()<<endl;
    //cout<<upper_bound(end(v),begin(v),7)-v.begin()<<endl;
    //int *a[3];
    //cout<<*a;
    //Node* ptr = new Node(100,200);
    //cout<<((ptr!=NULL)?(ptr->x):(0));
    vector<int> vec;
    vec.assign({1,5,3,5,2,3});
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();++i)
        cout<<vec[i]<<" ";
    


    return 0;
}
