class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int maxGap=0;
        for(int i=1;i<n;i++){
            maxGap=max(maxGap,nums[i]-nums[i-1]);
        }
        return maxGap;
        
    }
};