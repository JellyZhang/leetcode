/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        //string ans = "";
        //if(num1.size()<num2.size()){
            //swap(num1,num2);
        //}
        //for(int i=0;i<num2.size();++i){
            //string temp = strMulti(num1,num2[num2.size()-1-i]-'0');
            //temp.insert(temp.size(),i,'0');
            //ans = strPlus(ans,temp);
        //}
        //return ans;
        string ans(num1.size()+num2.size(),'0');
        for(int i=num1.size()-1;i>=0;i--){
            int carry = 0;
            for(int j=num2.size()-1;j>=0;j--){
                int tmp = (ans[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0') + carry;
                ans[i+j+1] = tmp%10+'0';
                carry = tmp/10;
            }
            ans[i] = carry +'0';
        }
        int pos = ans.find_first_not_of('0');
        if(pos == string::npos)
            return "0";
        return ans.substr(pos);
    }
    string strMulti(string num1, int n){
        if(n==0)
            return "0";
        string ans = "";
        int carry = 0;
        for(int i=0;i<num1.size();++i){
            int temp = (num1[num1.size()-1-i]-'0')*n;
            temp += carry;
            carry = 0;
            while(temp>=10){
                temp -= 10;
                carry++;
            }
            ans += to_string(temp);
        }
        if(carry){
            ans += to_string(carry);
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
    string strPlus(string &num1, string &num2){
        string ans = "";
        int i = 0;
        int carry = 0;
        while(i<num1.size() || i<num2.size() || carry){
            int temp = (i<num1.size())?(num1[num1.size()-1-i]-'0'):0;
            temp += (i<num2.size())?(num2[num2.size()-1-i]-'0'):0;
            temp += carry;
            carry = 0;
            if(temp>=10){
                temp -= 10;
                carry = 1;
            } 
            ans += to_string(temp);
            i++;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
// @lc code=end
