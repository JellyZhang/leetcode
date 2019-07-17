#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }   
        int i =0;
        while(1){
            bool IsEnd = false;
            for(auto str:strs){
                if(i==(int)str.length()){
                    IsEnd = true;
                    break;
                }
            }
            if(IsEnd){
                break;
            }
            char now =strs.at(0).at(i);
            for(auto str:strs){
                if(str.at(i)!=now){
                    IsEnd = true;
                    break;
                }
            }
            if(IsEnd){
                break;
            }
            ++i;
        }
        return strs.at(0).substr(0,i);
    }
};
//int main(){
    //vector<string> strs = {"flaaa","flbbb"};
    //Solution a;
    //cout<<a.longestCommonPrefix(strs);

    //return 0;
//}
