class Solution {
public:
    //[],...
    //...,[]
    //[],[]
    //t.len>s.len
    string minWindow(string s, string t) {
        int len1=s.size();
        int len2=t.size();
        //corner case
        if(len1*len2==0 || len1<len2){
            return "";
        }
        //unordered_map<char,int> imap;
        vector<int> imap(128,0);
        for(int i=0;i<len2;++i){
            imap[t[i]]++;
        }
        int left_to_match=len2;
        int left=0;
        int ans_len=len1+1;
        int ans_left=0;
        for(int right=0;right<len1;right++){
            //vector version
            if(imap[s[right]]>0){
                left_to_match--;
            }
            imap[s[right]]--;
            while(left_to_match==0){
                if(right-left<ans_len){
                    ans_len=right-left;
                    ans_left=left;
                }
                if(imap[s[left]]==0){
                    left_to_match++;
                }
                imap[s[left]]++;
                left++;
            }







            //map version
            //
            //if(imap.find(s[right])!=imap.end()){
                //imap[s[right]]--;
                ////if is effective match
                //if(imap[s[right]]>=0){ 
                    //left_to_match--;
                //}
                //while(left_to_match==0){
                    //if(right-left<ans_len){
                        //ans_len=right-left;
                        //ans_left=left;
                    //}
                    //if(imap.find(s[left])!=imap.end()){
                        //imap[s[left]]++;
                        //if(imap[s[left]]>0){
                            //left_to_match++;
                        //}
                    //}
                    //left++;
                //}
            //}
        }
        if(ans_len==len1+1){
            return "";
        }
        else{
            return s.substr(ans_left,ans_len+1);
        }
        
    }
};
