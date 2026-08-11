class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int k=nums.size();
        if(k==1 && nums[0]==0 && n==1){
            return true;
        }
        if(k==1 && nums[0]==1 && n==1) {
            return false;
        }
        if(n==0){
            return true;
        }
        for(int i=0;i<k;i++){
            if(i==0 && nums[i]==0){
                if(i+1<k && nums[i+1]==0){
                    n--;
                    if(n==0){
                        return true;
                    }
                    nums[i]=1;
                }
            }
            else if(i==k-1){
                if(nums[i]==0 && nums[i-1]==0){
                    n--;
                    if(n==0){
                        return true;
                    }
                    nums[i]=1;
                }
            }
            else if(nums[i]==0){
                if(i-1>=0 && i+1<k && nums[i-1]==0 && nums[i+1]==0){
                     n--;
                     if(n==0){
                        return true;
                     }
                     nums[i]=1;
                }
            }
        }
        cout<<n;
        return n==0;
        
    }
};