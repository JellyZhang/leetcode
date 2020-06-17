#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <map>
#include <stdio.h>

using namespace std;

int main(){
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,t;
        map<int,int> indexs;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>t;
            indexs[t] = i;
        }
        int pre = INT_MAX;
        int ans = 0;
        for(auto it=indexs.rbegin();it!=indexs.rend();it++){
            cout<<"pre="<<pre<<" cur="<<it->second<<endl;
            if(pre < it->second){
                cout<<"DO"<<endl;
                ans++;
            }
            pre = min(pre,it->second);
            //cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
