class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int i=0,j=n-1;
        int cnt=0;
        int sum=0;
        while(i<j){
            sum=nums[i]+nums[j];
            if(sum<=limit){
                i++,j--;
                cnt++;
            }
            else{
                j--;
                cnt++;
            }
        }
        return (i==j)?cnt+1:cnt;
        
    }
};