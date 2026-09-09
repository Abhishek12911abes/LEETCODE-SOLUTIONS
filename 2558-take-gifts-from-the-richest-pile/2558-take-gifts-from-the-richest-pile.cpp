class Solution {
public:
    // long long solve(long long maxi){
    //     return sqrt(maxi);
    // }
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();

        long long ans=0;

        priority_queue<int>pq;

        for(int num : gifts){
            pq.push(num);
        }

        while(k--){
            long long maxi=pq.top();
            pq.pop();

            pq.push(sqrt(maxi));
        }

        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;

        
    }
};