class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();

        priority_queue<int>pq;
        // max_heap

        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int maxi=pq.top();
            pq.pop();
            int smaxi=pq.top();
            pq.pop();

            if(maxi==smaxi){
                pq.push(0);
            }
            if(maxi!=smaxi){
               pq.push(maxi-smaxi);
            }

        }
        return pq.top();
        
    }
};