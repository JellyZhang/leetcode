class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> files;
        for(string path:paths){
            stringstream ss(path);
            string root;
            string file;
            getline(ss,root,' ');
            while(getline(ss,file,' ')){
                string filename = root+'/'+file.substr(0,file.find('('));
                string content = file.substr(file.find('('));
                files[content].push_back(filename);
            }
        }
        vector<vector<string>>ans;
        for(auto entry:files){
            if(entry.second.size()>1)
                ans.push_back(entry.second);
        }
        return ans;
    }
};
