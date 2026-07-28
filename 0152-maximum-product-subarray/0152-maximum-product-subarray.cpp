class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        int prod=1;

        vector<int>pref(n),suff(n);

        pref[0]=nums[0];

        for(int i=1;i<n;i++){
            pref[i]=nums[i]*(pref[i-1]==0?1:pref[i-1]);
        }

        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=nums[i]*(suff[i+1]==0?1:suff[i+1]);
        }
        int maxProd=-1e9;
        for(int i=0;i<n;i++){
            maxProd=max({maxProd,pref[i],suff[i]});
        }
        return maxProd;
    }
};