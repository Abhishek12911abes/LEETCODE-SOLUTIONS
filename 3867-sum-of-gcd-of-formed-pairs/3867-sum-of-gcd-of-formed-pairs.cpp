class Solution {
public:
    typedef long long ll;
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        vector<ll>prefixGCD(n);
        prefixGCD[0]=nums[0];
        for(int i=1;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefixGCD[i]=gcd(nums[i],maxi);
        }
        sort(begin(prefixGCD),end(prefixGCD));
        ll sum=0;
        for(int i=0;2*i<n;i++){
            sum+=gcd(prefixGCD[i],prefixGCD[n-i-1]);
        }
        return n%2==1?sum-prefixGCD[n/2]:sum;
    }
};