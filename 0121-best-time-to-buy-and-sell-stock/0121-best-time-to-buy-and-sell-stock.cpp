class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int maxProfit=0;
        int minSoFar=INT_MAX;

        for(int i=0;i<n;i++){
            minSoFar=min(minSoFar,nums[i]);
            if(nums[i]>minSoFar){
                maxProfit=max(maxProfit,nums[i]-minSoFar);
            }
        }
        return maxProfit;
        
    }
};