class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0;
        double maxAvg=INT_MIN;
        int i=0,j=0;
        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1>k){
                sum-=nums[i];
                i++;
            }
            if(j-i+1==k){
                double avg=sum/k;
                maxAvg=max(maxAvg,avg);
            }
            j++;
        }
        return maxAvg;
        
    }
};