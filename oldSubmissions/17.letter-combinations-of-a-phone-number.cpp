#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        vector<string> ans;
        queue<string> Q;
        ans.clear();
        Q.push("");
        while(digits.size()!=0){
            string str = "";
            switch(digits[0]){
                case '2':
                    str="abc";
                    break;
                case '3':
                    str="def";
                    break;
                case '4':
                    str="ghi";
                    break;
                case '5':
                    str="jkl";
                    break;
                case '6':
                    str="mno";
                    break;
                case '7':
                    str="pqrs";
                    break;
                case '8':
                    str="tuv";
                    break;
                case '9':
                    str="wxyz";
                    break;
            }
            digits.erase(0,1);
            int temp_size=Q.size();
            for(int i=0;i<temp_size;i++){
                string first = Q.front();
                Q.pop();
                for(int j=0;j<str.size();j++){
                    Q.push(first+str[j]);
                }
            }
        }
        while(!Q.empty()){
            ans.push_back(Q.front());
            Q.pop();
        }
        return ans;
    }
};
