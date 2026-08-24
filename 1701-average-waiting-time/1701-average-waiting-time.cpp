class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double sum=0;
        int prepareAt=0,finishTime=0;
        for(int i=0;i<n;i++){
            int arrival=customers[i][0];
            int time=customers[i][1];
            if(i==0){
                prepareAt=arrival;
                finishTime=prepareAt+time;
            }
            else{
                if(arrival<finishTime){
                    prepareAt=finishTime;
                    finishTime=prepareAt+time;
                }
                else{
                    prepareAt=arrival;
                    finishTime=prepareAt+time;
                }
            }
            int waitingTime=finishTime-arrival;
            sum+=waitingTime;
        }
        return (1.0*sum)/n;
        
    }
};