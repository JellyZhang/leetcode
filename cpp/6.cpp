#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || s.size()<=numRows)return s;
        const int rows=numRows;
        string result[rows],ans;
        int flag=0;//0 down,1 up
        int k=0;
        for(int i=0;i<s.size();i++){
            result[k]+=s[i];
            if(flag==0)k++;
            else k--;
            if(k==0)flag=0;
            if(k==rows-1)flag=1;
        }
        for(int i=0;i<rows;i++)ans+=result[i];
        return ans;
    }
};

int main(){
    string a;
    cin>>a;
    Solution s;
    cout<<s.convert(a,1);
    return 0;
}
