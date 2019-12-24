class Solution {
public:
    //["a"]\n100
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start = 0;
        int end = start;
        int total_len = 0;
        vector<string>ans;
        while(start<words.size()){
            end = start;
            total_len = 0;
            while(end<words.size() && total_len + words[end].size() <= maxWidth){
                total_len+=words[end].size()+1;
                end++;
            }
            if(end==words.size()){
                //end of words
                string temp = "";
                while(start<end){
                    temp+=words[start++];
                    temp+=" ";
                }
                temp.pop_back();
                while(temp.size()<maxWidth)
                    temp.push_back(' ');
                ans.push_back(temp);
            }
            else{
                //normal line
                string temp = "";
                if(end-start-1==0){
                    temp+=words[start++];
                    temp.append(maxWidth - total_len + 1,' ');
                    ans.push_back(temp);
                    continue;
                }
                int nums_zero = maxWidth - total_len + (end-start);
                int averager_zero = nums_zero/(end-start-1);
                int left_zeros = nums_zero-averager_zero*(end-start-1);
                //cout<<left_zeros<<" ";
                while(start<end){
                    temp+=words[start];
                    if(start!=end-1){
                        temp.append(averager_zero,' ');
                        if(left_zeros-->0)
                            temp+=' ';
                    }
                    start++;
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
