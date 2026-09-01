class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int minOps=0;
            for(int k=0;k<i;k++){
                if(boxes[k]=='1'){
                    minOps+=abs(k-i);
                }
            }
            for(int j=i+1;j<n;j++){
                if(boxes[j]=='1'){
                    minOps+=abs(j-i);
                }
            }
            ans.push_back(minOps);
        }
        return ans;
        
        
    }
};