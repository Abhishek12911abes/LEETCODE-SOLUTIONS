class Solution {
public:
    int n;
    // int t[1001];
    // int solve(int idx , vector<int>& nums , int n){
    //     if(idx>n){
    //         return 0;
    //     }

    //     if(t[idx]!=-1){
    //         return t[idx];
    //     }

    //     int rob=nums[idx]+solve(idx+2,nums,n);
    //     int skip=solve(idx+1,nums,n);

    //     return t[idx]=max(rob,skip);
    // }
    int rob(vector<int>& nums) {
        n=nums.size();

        if(n==1){
            return nums[0];
        }

        // if(n==2){
        //     return max(nums[0],nums[1]);
        // }
        // memset(t,-1,sizeof(t));
        // int idx0=solve(0,nums,n-2);

        // memset(t,-1,sizeof(t));
        // int idx1=solve(1,nums,n-1);

        // return max(idx0,idx1);

        vector<int>dp(n+1,0);
        
        // Case 1 ) Take 1st House and skip last House

        // State Defn -> dp[i]=money stolen when u have i houses;

        dp[0]=0;

        for(int i=1;i<=n-1;i++){
            int skip=dp[i-1];
            int rob=nums[i-1]+((i-2>=0)?dp[i-2]:0);

            dp[i]=max(skip,rob);
        }
        int res1=dp[n-1];

        dp.clear();

        //Case 2 ) Skip 1st House and hence take last house;

        dp[0]=0;

        dp[1]=0; // i have skipped first house;

        for(int i=2;i<=n;i++){
            int skip=dp[i-1];
            int rob=nums[i-1]+((i-2>=0)?dp[i-2]:0);

            dp[i]=max(skip,rob);
        }
        int res2=dp[n];

        return max(res1,res2);
    }

};