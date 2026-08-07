class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int>ans;

        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++){
            vec[i]={arr[i],abs(arr[i]-x)};
        }

        sort(begin(vec),end(vec),[&](auto &a , auto &b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second<b.second;
        });
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].first);
        }
        sort(ans.begin(), ans.end());
        return ans;

        
    }
};