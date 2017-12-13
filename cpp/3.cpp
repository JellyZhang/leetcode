#include <bits/stdc++.h>
using namespace std;


int longestSubstringFrom(string a,int index){
    unordered_map<char,int> mymap;
    int result=0;
    for(int i=index;i!=a.size();i++){
        if(mymap.find(a[i])!=mymap.end()){
            return result;
        }
        else{
            mymap.insert({a[i],i});
            result++;
        }
    }
    return result;
}
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        int i=0;
        int j;
        const int len=s.size();
        int result[len];
        for(int t=0;t<len;t++)result[t]=1;
        while(true){
            j=i+longestSubstringFrom(s,i);
            while(s[i]!=s[j]){
                result[i]=j-i;
                i++;
            }
            i++;
            if(j==s.size())break;
        }
        int max=1;
        for(int t=0;t<len;t++)
            if(result[t]>max)max=result[t];
        return max;

    }
};

int main(){
    string a;
    cin>>a;
    Solution s;
    cout<<s.lengthOfLongestSubstring(a);
    return 0;
}
