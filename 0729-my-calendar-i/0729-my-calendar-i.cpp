//Approach (Using Line Sweep)
//T.C : O(nlogn)
//S.C : O(n) to store events in map
class MyCalendar {
public:
    map<int, int> events;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        events[startTime]++;
        events[endTime]--;

        int count = 0;

        for(auto &it : events) {
            count += it.second;

            if(count > 1) {
                events[startTime]--;
                events[endTime]++;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */