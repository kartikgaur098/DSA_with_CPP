class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int startIndex = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalCost = cost[i] + totalCost;
            totalGas = gas[i] + totalGas;
        }
        if (totalGas < totalCost)
            return -1;

        int currGas = 0;

        for (int i = 0; i < gas.size(); i++) {
            currGas = currGas + gas[i] - cost[i];

            if (currGas < 0) {
                currGas = 0;
                startIndex = i + 1;
            }
        }
        return startIndex;
    }
};