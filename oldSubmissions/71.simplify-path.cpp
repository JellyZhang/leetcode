#include <string>
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir_names;
        int len = path.size();
        if(len==0){
            return "";
        }
        //slash pos
        int left = 0;
        int right = 0;
        while(true){
            //check end
            if(right==len){
                break;
            }
            //set left
            left=right;
            // find next right slash pos
            for(right=left+1;right<len;++right){
                if(path[right]=='/'){
                    break;
                }
            }
            // deal with substr
            int temp = right-left-1;
            if(temp==0 || (temp==1 && path[left+temp]=='.')){
                continue;
            }
            else if(temp==2 && path[left+1]=='.' && path[left+2]=='.'){
            //cout<<"!"<<left<<" "<<right;
                if(!dir_names.empty()){
                    dir_names.pop_back();
                }
            }
            else{
                string sub = path.substr(left+1,temp);
                dir_names.push_back(sub);
                cout<<"!"<<sub;
            }
        }
        string ans ="";
        if(dir_names.size()==0){
            ans = "/";
            return ans;
        }
        for(int i=0;i<dir_names.size();++i){
            ans +="/";
            ans += dir_names[i];
        }
        return ans;
        
    }
};
