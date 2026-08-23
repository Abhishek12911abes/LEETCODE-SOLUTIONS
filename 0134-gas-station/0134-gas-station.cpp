class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        // for (int start = 0; start < n; start++) {

        //     int tank = 0;
        //     int count = 0;
        //     int idx = start;

        //     while (count < n) {
        //         tank += gas[idx] - cost[idx];

        //         if (tank < 0) {
        //             break;
        //         }

        //         idx = (idx + 1) % n;
        //         count++;
        //     }

        //     if (count == n) {
        //         return start;
        //     }
        // }

        // return -1;

        int sumGas = accumulate(begin(gas), end(gas), 0);
        
        int sumCost = accumulate(begin(cost), end(cost), 0);
        
        if(sumGas < sumCost)
            return -1;
        
        int total  = 0;
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            
            total += gas[i] - cost[i];
            
            if(total < 0) {
                total = 0;
                result = i+1;
            }
            
        }
        return result;
    }
};