class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        unordered_map<int,int>mp;

        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if(nums2[j]>nums2[i]){
                    mp[nums2[i]]=nums2[j];
                    break;
                }
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int num=nums1[i];
            if(mp.find(num)==mp.end()){
                ans[i]=-1;
            }
            else{
                ans[i]=mp[num];
            }
        }
        return ans;

        
    }
};