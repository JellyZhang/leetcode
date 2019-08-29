class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //int sum1=0,sum2=0;
        //for(int i=0;i<gas.size();++i){
            //sum1+=gas[i];
            //sum2+=cost[i];
        //}
        //if(sum1<sum2||gas.size()==0)
            //return -1;
        //int i=0;
        //while(true){
            //while(gas[i]<cost[i])
                //++i;
            //int j=i;
            //int sum=0;
            //while(sum>=0 && j<gas.size()){
                //sum+=gas[j]-cost[j];
                //j++;
            //}
            ////cout<<j<<" ";
            //if(j==gas.size()){
                //break;
            //}
            //i=j;
        //}
        //return i;
        int sum1=0,sum2=0;
        for(int i=0;i<gas.size();++i){
            sum1+=gas[i];
            sum2+=cost[i];
        }
        if(sum1<sum2||gas.size()==0)
            return -1;
        int sum=gas[0]-cost[0];
        int lowest_sum=gas[0]-cost[0];
        int lowest_index=0;
        for(int i=1;i<gas.size();++i){
            sum+=gas[i]-cost[i];
            if(sum<lowest_sum){
                lowest_sum=sum;
                lowest_index=i;
            }
        }
        return (lowest_index+1)%gas.size();
    }
};
