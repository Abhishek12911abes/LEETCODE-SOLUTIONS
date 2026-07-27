class Solution {
public:
    int n;
    int t[1001];
    int solve(int idx , vector<int>& nums , int n){
        if(idx>n){
            return 0;
        }

        if(t[idx]!=-1){
            return t[idx];
        }

        int rob=nums[idx]+solve(idx+2,nums,n);
        int skip=solve(idx+1,nums,n);

        return t[idx]=max(rob,skip);
    }
    int rob(vector<int>& nums) {
        n=nums.size();

        if(n==1){
            return nums[0];
        }

        if(n==2){
            return max(nums[0],nums[1]);
        }
        memset(t,-1,sizeof(t));
        int idx0=solve(0,nums,n-2);

        memset(t,-1,sizeof(t));
        int idx1=solve(1,nums,n-1);

        return max(idx0,idx1);
        
    }
};