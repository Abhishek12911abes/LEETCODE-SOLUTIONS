class MedianFinder {
public:
    priority_queue<int>left_max_heap;
    priority_queue<int,vector<int>,greater<int>>right_min_heap;
    MedianFinder() {
        
    }
    void addNum(int num) {
        if(left_max_heap.empty() || left_max_heap.top()>=num){
            left_max_heap.push(num);
        }
        else{
            right_min_heap.push(num);
        }

        if(left_max_heap.size()>right_min_heap.size()+1){
            int x=left_max_heap.top();
            left_max_heap.pop();
            right_min_heap.push(x);
        }
        else if(right_min_heap.size()>left_max_heap.size()){
            int y=right_min_heap.top();
            right_min_heap.pop();
            left_max_heap.push(y);
        }
    }
    
    double findMedian() {
        double mean;
        if(left_max_heap.size()==right_min_heap.size()){
            mean=(left_max_heap.top()+right_min_heap.top())/2.0;
        }
        else{
            return left_max_heap.top();
        }
        return mean;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */