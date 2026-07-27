class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=-1,smaxi=-1;
        for(int num : nums){
            if(num>maxi){
                smaxi=maxi;
                maxi=num;
            }
            else if(num>smaxi){
                smaxi=num;
            }
        }
        return (maxi-1)*(smaxi-1);
        
    }
};