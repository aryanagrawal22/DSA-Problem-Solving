class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //If sum of total cost is greater than total refill then return -1
        if(accumulate(cost.begin(), cost.end(), 0)>accumulate(gas.begin(), gas.end(), 0)) return -1;
        
        //Make start from 0 and extra (surplus fuel) as 0
        int start = 0, extra = 0;
        for(int i = 0;i<gas.size(); i++){
            
            //Keep adding gas left after travel and if it is less than 0 then reset the extra to 0 and make start from next index as all the values before it are not possible as no surplus fuel is left
            extra += gas[i]-cost[i];
            if(extra<0){
                extra = 0;
                start = i+1;
            }
        }
        return start;
    }
};