class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n=seats.size();
        sort(begin(seats),end(seats));
        sort(begin(students),end(students));
        int count=0;
        for(int i=0;i<n;i++){
            count+=abs(seats[i]-students[i]);
        }
        return count;
        
        
    }
};