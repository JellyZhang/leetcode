class Solution {
public:
    int getsum(int n){
        int sum = 0;
        while(n){
            sum+= (n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_map<int,int>hash;
        int t = n;
        while(!hash.count(t)){
            hash[t]=1;
            if(t==1)
                return true;
            t = getsum(t);
        }
        return false;
    }
};
