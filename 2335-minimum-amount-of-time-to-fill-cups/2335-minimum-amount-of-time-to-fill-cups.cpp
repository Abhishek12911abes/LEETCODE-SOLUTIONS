class Solution {
public:
    int fillCups(vector<int>& amount) {
        // 5 4 4
            // 4 3 4 - 1
            // 3 3 3 - 2
            // 2 2 3 - 3
            // 1 2 2 - 4
            // 1 1 1 - 5
            // 0 0 1 - 6
            // 0 0 0 - 7

            priority_queue<int>pq(begin(amount),end(amount));
        
            int ops=0;
            while(pq.top()!=0){
                int maxi=pq.top();
                pq.pop();
                int smaxi=pq.top();
                pq.pop();

                pq.push(maxi-1);
                pq.push(smaxi-1);

                ops++;
            }
            return ops;
    }
};