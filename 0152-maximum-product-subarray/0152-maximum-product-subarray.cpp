class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pre=1,suff=1;
        int maxProd=INT_MIN;
        for(int i=0;i<n;i++){
            pre*=nums[i];
            suff*=nums[n-i-1];
            maxProd=max({maxProd,pre,suff});
            if(nums[i]==0){
                pre=1;
            }
            if(nums[n-i-1]==0){
                suff=1;
            }
        }
        return maxProd;

        // -2 0 -1
        // pre -2 0 0
        // suff -1 0 0
        // max -1 0 0

        
    }
};