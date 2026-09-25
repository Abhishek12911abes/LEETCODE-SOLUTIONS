class Solution {
public:
    int n;
    int solve(vector<int>& nums , unordered_map<int,int>& mp , int elem , int maxElem, vector<int>&dp){
        if(elem>maxElem){
            return 0;
        }

        if(dp[elem]!=-1){
            return dp[elem]; 
        }
        int take=0,skip=0;

        take=mp[elem]*elem+solve(nums,mp,elem+2,maxElem,dp);

        skip=solve(nums,mp,elem+1,maxElem,dp);

        return dp[elem]=max(take,skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        n=nums.size();
        unordered_map<int,int>mp;



        sort(begin(nums),end(nums));

        int maxElem=nums.back();

        for(int num : nums){
            mp[num]++;
        }

        vector<int>dp(maxElem+1,-1);

        return solve(nums,mp,nums[0],maxElem,dp);
    }
};