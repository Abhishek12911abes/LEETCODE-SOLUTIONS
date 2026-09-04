class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int smallIdx=INT_MAX;
        int maxi=-1;
        vector<int>mini(n);
        mini[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            mini[i]=min(nums[i],mini[i+1]);
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            cout<<maxi<<" ";
            int mn=mini[i];
            cout<<mn<<" ";
            if(maxi-mn<=k && i<smallIdx){
                smallIdx=i;
            }
        }
        return smallIdx==INT_MAX?-1:smallIdx;
        
    }
};