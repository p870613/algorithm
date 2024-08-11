class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>>minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);

        if (!minheap.empty() && !maxheap.empty() && maxheap.top() > minheap.top()) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }

        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        if (minheap.size() > maxheap.size() + 1) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if (minheap.size() == maxheap.size())
            return (minheap.top() + maxheap.top()) / 2.0;
        return maxheap.size() > minheap.size() ? maxheap.top() : minheap.top();       
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */