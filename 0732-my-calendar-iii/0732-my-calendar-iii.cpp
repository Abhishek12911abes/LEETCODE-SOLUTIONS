class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;

        int booking=0;
        int maxBooking=0; 
        for(auto &it : mp){
            booking+=it.second;
            if(booking>maxBooking){
                maxBooking=booking;
            }

        }
        return maxBooking;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */