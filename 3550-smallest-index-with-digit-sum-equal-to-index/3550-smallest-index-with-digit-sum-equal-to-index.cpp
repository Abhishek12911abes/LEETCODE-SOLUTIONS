class Solution {
public:
    int solve(int temp){
        int s=0;
        while(temp){
            s+=temp%10;
            temp/=10;
        }
        return s;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=solve(nums[i]);
            if(sum==i){
                return i;
            }
        }
        return -1;
        
    }
};