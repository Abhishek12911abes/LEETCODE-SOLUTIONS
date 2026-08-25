class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int countOne=count(begin(nums),end(nums),1);
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        int minSwaps=INT_MAX;
        int i=0,j=0;
        int zeroCount=0;
        while(j<2*n){
            zeroCount=(nums[j]==0)?(zeroCount+1):zeroCount;
            if(j-i+1>countOne){
                zeroCount=(nums[i]==0)?(zeroCount-1):zeroCount;
                i++;
            }
            if(j-i+1==countOne){
                minSwaps=min(minSwaps,zeroCount);
            }
            j++;
        }
        return minSwaps;
        
    }
};