class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<int>prefix(1001,0);
        for(int i=0;i<n;i++){
            int passenger=trips[i][0];
            int from=trips[i][1];
            int to=trips[i][2];

            for(int j=from;j<to;j++){
                prefix[j]+=passenger;
            }

        }

        for(int i=0;i<1001;i++){
            if(prefix[i]>capacity){
                return false;
            }
        }
        return true;
        
    }
};