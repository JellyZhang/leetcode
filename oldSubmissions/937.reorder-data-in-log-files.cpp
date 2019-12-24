        bool mycompare(const string & log1,const string& log2){
            int index1=0,index2=0;
            while(log1[index1]!=' ')
                index1++;
            while(log2[index2]!=' ')
                index2++;
            if(isalpha(log1[index1+1]) && isalpha(log2[index2+1])){
                if(log1.substr(index1+1)==log2.substr(index2+1))
                    return log1.substr(0,index1+1)<log2.substr(0,index2+1);
                else
                    return log1.substr(index1+1)<log2.substr(index2+1);
            }
            else if(isalpha(log1[index1+1])){
                return true;
            }
            else 
                return false;
        }
class Solution {
public:
    void mysplit(const string& str,vector<string>& cont,char delim){
        stringstream ss(str);
        string token;
        while(getline(ss,token,delim)){
            cont.push_back(token);
        }
        return;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(),logs.end(),mycompare);
        return logs;
    }
};
