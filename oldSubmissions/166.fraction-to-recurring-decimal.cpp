class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        unordered_map<int,int>showed;
        bool isnegetive = (numerator*denominator<0)?(true):(false);
        numerator = abs(numerator);
        denominator = abs(denominator);
        long long ans_int = numerator/denominator;
        vector<int>ans_decimal;
        long long interg = numerator %= denominator;
        while(interg && !showed.count(interg)){
            showed[interg] = ans_decimal.size();
            interg *= 10;
            ans_decimal.push_back(interg/denominator);
            interg %= denominator;
        }
        if(ans_decimal.size()==0){
            string ans = to_string(ans_int);
            if(isnegetive)
                ans = '-' + ans;
            return ans;
        }
        string ans = to_string(ans_int)+'.';
        if(showed.count(interg)){
            int i =0;
            for(;i<showed[interg];++i)
                ans += ans_decimal[i]+'0';
            ans += '(';
            for(;i<ans_decimal.size();++i){
                ans += ans_decimal[i]+'0';
            }
            ans += ')';
        } else{
            for(int i=0;i<ans_decimal.size();++i){
                ans += ans_decimal[i]+'0';
            }
        }
        if(isnegetive)
            ans = '-'+ans;
        return ans;
    }
};
