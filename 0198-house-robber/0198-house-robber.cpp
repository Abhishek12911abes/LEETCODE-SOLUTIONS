class Solution {
public:
    // vector<int>dp;
    // int solve(vector<int>& nums, int idx){
    //     if(idx>=nums.size()) return 0;
    //     if(dp[idx]!=-1){
    //         return dp[idx];
    //     }
    //     int pick=nums[idx]+solve(nums,idx+2);
    //     int not_pick=solve(nums,idx+1);
    //     return dp[idx]=max(pick,not_pick);

    // }
    int rob(vector<int>& nums) {
        // Recursion + Memo
        // dp.assign(nums.size(),-1);
        // return solve(nums,0);

        int n=nums.size();
        // Bootom up
         if(n == 1)
            return nums[0];
        
        vector<int> t(n+1);
        //t[i] = max profit till house i
        
        t[0] = 0;
        t[1] = nums[0];
        
        for(int i = 2; i<=n; i++) {
            
            int skip  = t[i-1];
            int steal = nums[i-1] + t[i-2];
          
            t[i] = max(skip, steal); //max(skip, steal)
            /*
                SKIP  : If we skip this house,  then we have money till previous house  =  t[i-1]
                STEAL : If we steal this house, then we can't take prev profit, we can take till (i-2)th house profit = t[i-2]
            */
        }
        
        return t[n];
        
    }
};