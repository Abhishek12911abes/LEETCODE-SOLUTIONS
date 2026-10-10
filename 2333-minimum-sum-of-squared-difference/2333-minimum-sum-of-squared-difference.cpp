class Solution {
public:
    typedef long long ll;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        // long long sum=0;
        // for(int i=0;i<n;i++){
        //     long long diff=(nums1[i]-nums2[i]);
        //     sum+=1LL*diff*diff;
        // }
        // if(k1==0 && k2==0){
        //     return sum;
        // }
        // priority_queue<int>pq;
        // for(int i=0;i<n;i++){
        //     pq.push(abs(nums1[i]-nums2[i]));
        // }
        // int k=k1+k2;
        // while(k-- && pq.top()>0){
        //     int maxi=pq.top();
        //     pq.pop();
        //     pq.push(maxi-1);
        // }
        // long long ans=0;
        // while(!pq.empty()){
        //     int maxi=pq.top();
        //     pq.pop();
        //     ans+=1LL*maxi*maxi;
        // }
        // return ans;

        // Optimal 
        vector<int>diff(1e5+1,0);
        for(int i=0;i<n;i++){
            int d=abs(nums1[i]-nums2[i]);
            diff[d]++;
        }

        int k=k1+k2;

        for(int i=1e5;i>0 && k>0 ; i--){
            int freq = min(diff[i],k);

            diff[i]     -= freq;
            diff[i-1]   += freq;

            k-= freq;
        }
        ll ans=0;
        for(int i=0;i<=1e5;i++){
            ans+= 1LL*diff[i]*i*i;
        }
        return ans;
    }

};