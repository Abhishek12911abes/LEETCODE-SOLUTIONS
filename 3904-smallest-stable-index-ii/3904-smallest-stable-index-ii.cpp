class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefixMin(n);
        prefixMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            prefixMin[i]=min(nums[i],prefixMin[i+1]);
        }
        int maxi=INT_MIN;
        int score=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            score=maxi-prefixMin[i];
            if(score<=k){
                return i;
            }
        }
        return -1;
        
    }
};