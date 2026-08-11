class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int seqSum=nums[0];
        int maxSum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                seqSum+=nums[i];
                maxSum=max(maxSum,seqSum);
            }
            else{
                break;
            }
        }
        unordered_set<int>st(begin(nums),end(nums));
        for(int i=maxSum;i<=1275;i++){
            if(!st.count(i)){
                return i;
            }
        }
        return -1;
        
    }
};