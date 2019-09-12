class Solution {
public:
    int mySqrt(int x) {
        if(x<2)
            return x;
        int lo = 1;
        int hi = x-1;
        while(lo<=hi){
            long long mid = (lo+hi)>>1;
            if(mid*mid>x){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        //return hi;
        return newton(x);
    }
    int newton(int x){
        if(x<2)
            return x;
        double x0 = x;
        double x1 = (x0 + x/x0)/2.0;
        while(abs(x1-x0)>=1.0){
            x0 = x1;
            x1 = (x0 + x/x0)/2.0;
        }
        return (int)x1;
    }
};
