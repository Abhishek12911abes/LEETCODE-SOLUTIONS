class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxiIdx=-1,miniIdx=-1;
        int maxi=INT_MIN,mini=INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxiIdx=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                miniIdx=i;
            }
        }
        int front=max(miniIdx+1,maxiIdx+1);
        int back=max((n-miniIdx),(n-maxiIdx));
        int mix=min(maxiIdx+1+(n-miniIdx),miniIdx+1+(n-maxiIdx));
        return min({front,back,mix});
    }
};