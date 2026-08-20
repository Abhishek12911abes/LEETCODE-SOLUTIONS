class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            if(arr1[arr1.size()-1]>arr2[arr2.size()-1]){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }
        vector<int>ans;
        for(int num : arr1){
            ans.push_back(num);
        }
        for(int num : arr2){
            ans.push_back(num);
        }
        return ans;
           
        
    }
    // nums  ke elem ko 2 array me distribute krna hai using n ops
    // nums1 to arr1 
    // nums2 to arr2
    // arr1[last]>arr2[last]-- nums[i] to arr1 or nums[i] to arr2

};