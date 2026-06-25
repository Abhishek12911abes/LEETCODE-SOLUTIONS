class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;

        vector<int>prefixSum(n,0);
        prefixSum[0]=nums[0]==target?1:0;
        for(int i=1;i<n;i++){
            prefixSum[i]=(nums[i]==target)?(prefixSum[i-1]+1):prefixSum[i-1];
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int cnt=(i-1>=0)?(prefixSum[j]-prefixSum[i-1]):prefixSum[j];
                if(2*cnt>j-i+1){
                    count++;
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        //     vector<int> num;
        //     for (int j = i; j < n; j++) {
        //         num.push_back(nums[j]);
        //         int n1 = num.size();
        //         int n2 = n1 / 2;
        //         int count1 = 0;
        //         for (int i = 0; i < n1; i++) {
        //             if (target == num[i]) {
        //                 count1++;
        //             }
        //         }
        //         if (count1 > n2) {
        //             count++;
        //         }
        //     }
        // }
        return count;
    }
};