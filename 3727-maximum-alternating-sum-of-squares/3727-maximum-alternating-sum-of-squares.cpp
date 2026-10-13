class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            temp.push_back(abs(nums[i]));
        }
        sort(begin(temp),end(temp));
        int mid=n/2;
        long long largerSum=0,smallerSum=0;
        for(int i=0;i<mid;i++){
            smallerSum+=1LL*temp[i]*temp[i];   
        }
        for(int i=mid;i<n;i++){
            largerSum+=1LL*temp[i]*temp[i];
        }
        return largerSum-smallerSum;
        
    }
};