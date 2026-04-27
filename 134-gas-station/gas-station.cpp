class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0;
        int totalcost = 0 ;
        int start = 0 ;
        int currGas = 0;
        for(int i = 0 ; i<gas.size() ; i++){
            totalcost += cost[i];
            totalgas += gas[i] ;

            currGas += gas[i] - cost[i];

            if(currGas < 0){
                start = i+1  ;
                currGas = 0 ;
            }

            
        }

        if(totalgas < totalcost){
                return -1 ;
            }

        return start ;
    }
};