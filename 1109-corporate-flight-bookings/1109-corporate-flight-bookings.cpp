class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int k=bookings.size();
        
        int maxLast=-1;
        for(auto &booking : bookings){
            int last=booking[1];
            maxLast=max(maxLast,last);
        }

        vector<int>diff(maxLast+1,0);
        for(auto &booking : bookings){
            int first   = booking[0];
            int last    = booking[1];
            int seat    = booking[2];
            diff[first] += seat;
            if(last+1<=maxLast)
                diff[last+1] -= seat;
        }
        vector<int>ans(n,0);
        ans[0]=diff[1];
        for(int i=2;i<=maxLast;i++){
            diff[i]+=diff[i-1];
            ans[i-1]=diff[i];
        }
        return ans;
        
        
    }
};