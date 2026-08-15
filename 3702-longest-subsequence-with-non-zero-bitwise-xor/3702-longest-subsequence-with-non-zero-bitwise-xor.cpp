class Solution {
public:
    int n;
    int solve(vector<int>& nums , int idx , int xorr){
        if(idx>=n){
            return 0;
        }
        int take=0;
        if((xorr^nums[idx])!=0){
            take=1+solve(nums,idx+1,xorr^nums[idx]);
        }
        int skip=solve(nums,idx+1,xorr);
        return max(take,skip);
    }
    int longestSubsequence(vector<int>& nums) {
        n=nums.size();
        int xr=0;
        bool allZero=true;
        for(int num : nums){
            if(num!=0){
                allZero=false;
            }
            xr^=num;
        }
        if(allZero){
            return 0;
        }
        if(xr==0){
            return n-1;
        }
        if(xr!=0){
            return n;
        }
        return solve(nums,0,0);
        
    }
};