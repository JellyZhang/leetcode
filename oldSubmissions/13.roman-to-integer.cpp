#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;    
class Solution {
public:
    
    std::unordered_map<string,int> RomanIntMap;
    int ans;
    void process(string s){
        if(s.empty()){
            return;
        }
        else if(1==s.length()){
            ans+=RomanIntMap.at(s);
        }
        else if(s.length()>=2){
            auto key = s.substr(0,2);
            if(RomanIntMap.find(key)!=RomanIntMap.end()){
                ans+=RomanIntMap.at(key);
                process(s.substr(2,100));
            }
            else{
                ans+=RomanIntMap.at(s.substr(0,1));
                process(s.substr(1,100));
            }
        }
    }
    int romanToInt(string s) {
        RomanIntMap.insert({"I",1});
        RomanIntMap.insert({"V",5});
        RomanIntMap.insert({"X",10});
        RomanIntMap.insert({"L",50});
        RomanIntMap.insert({"C",100});
        RomanIntMap.insert({"D",500});
        RomanIntMap.insert({"M",1000});
        RomanIntMap.insert({"IV",4});
        RomanIntMap.insert({"IX",9});
        RomanIntMap.insert({"XL",40});
        RomanIntMap.insert({"XC",90});
        RomanIntMap.insert({"CD",400});
        RomanIntMap.insert({"CM",900});
        ans=0;
        process(s);
        return ans;
    }


};
/*
int main(){

    Solution a;
    cout<<a.romanToInt("MCMXCIV");
    return 0;
}
*/
