class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        int sum1=accumulate(begin(nums1),end(nums1),0);
        int sum2=accumulate(begin(nums2),end(nums2),0);
        if(sum1==sum2){
            return 0;
        }   

        if(sum1>sum2){
            priority_queue<int>pq;
            for(int num : nums1){
                pq.push(num-1);
            }

            for(int num : nums2){
                pq.push(6-num);
            }

            int ops=0;
            int diff=sum1-sum2;
            
            while(!pq.empty() && diff>0){
                int maxi=pq.top();
                pq.pop();
                diff-=maxi;
                ops++;
            }
            return diff<=0?ops:-1;
        }
        else{
            priority_queue<int>pq;
            for(int num : nums1){
                pq.push(6-num);
            }
            for(int num : nums2){
                pq.push(num-1);
            }

            int ops=0;
            int diff=sum2-sum1;
            while(!pq.empty() && diff>0){
                int maxi=pq.top();
                pq.pop();
                diff-=maxi;
                ops++;
            }
            return diff<=0?ops:-1;
        }
        return -1;
        
    }
};