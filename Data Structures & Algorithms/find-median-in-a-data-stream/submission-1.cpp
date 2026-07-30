class MedianFinder {
public: 
    std::priority_queue<int> maxpq;
    std::priority_queue<int,std::vector<int>, std::greater<int>> minpq;
    int size =0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(size ==0 || num <=maxpq.top()){
            maxpq.push(num);
        } else {
            minpq.push(num);
        }
        if(maxpq.size()> minpq.size()+1){
            minpq.push(maxpq.top());
            maxpq.pop();
        } else if(maxpq.size()<minpq.size()){
            maxpq.push(minpq.top());
            minpq.pop();
        }
        size++;
    }
    
    double findMedian() {
        if(size ==0) return 0;
        if(size%2 == 0) {
            return  (maxpq.top() +minpq.top())/2.0;
        }
        return maxpq.top();
    }
};
