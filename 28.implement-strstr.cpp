#include <string>
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if(0==n){
            return 0;
        }
        if(0==m || m<n){
            return -1;
        }
        int shift[1005];
        for(int i=0;i<1005;i++){
            shift[i]=n+1;
        }
        for(int i=0;i<n;i++){
            shift[(int)needle[i]]=n-i;
        }

        for(int i =0;i<m-n+1;){
            int j=0;
            for(;j<n;j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
            }
            if(j==n){
                return i;
            }
            i+=shift[(int)haystack[i+n]];
        }
        return -1;
    }
};
/*
int main(){
    Solution s;
    cout<<s.strStr("aabaaaababaababaabbbb","bbbb");

    return 0;
}
*/
