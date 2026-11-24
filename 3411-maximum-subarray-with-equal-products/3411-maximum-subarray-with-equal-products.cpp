class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int maxLen=INT_MIN;
        for(int i=0;i<n;i++){
            unsigned long long int prod=nums[i];
            int hcf=nums[i];
            int lcm_val=nums[i];
            for(int j=i+1;j<n;j++){
                prod*=nums[j];
                hcf=gcd(hcf,nums[j]);
                lcm_val=lcm(lcm_val,nums[j]);
                if(hcf*lcm_val==prod){
                    maxLen=max(maxLen,j-i+1);
                }
            }
        }
        return maxLen;
        
    }
};