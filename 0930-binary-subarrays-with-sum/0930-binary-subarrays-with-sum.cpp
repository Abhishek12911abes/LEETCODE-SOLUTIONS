class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int target=sum-goal;
            if(mp.count(target)){
                count+=mp[target];
            }
            mp[sum]++;
        }
        return count;

        // ans = 4
        //  0 -1 
        //  1 - 2
        //  2 - 2
        // 3 -1
        //  1 target = -1
        //  1 target = -1
        //  2 target 0
        //  2 target 0
        //  3 target 1
        
    }
};