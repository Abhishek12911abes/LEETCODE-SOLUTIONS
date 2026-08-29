class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int maxSum=INT_MIN;
        int i=0,j=n-1;
        while(i<j){
            int sum=nums[i]+nums[j];
            maxSum=max(maxSum,sum);
            i++,j--;
        }
        return maxSum;
    }
};