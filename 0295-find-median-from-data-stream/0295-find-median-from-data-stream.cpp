class MedianFinder {
private:
    priority_queue<int> lower_max;
    priority_queue<int, vector<int>, greater<int>>upper_min;
    int usize = 0, lsize = 0;
public:
    MedianFinder() {
        lower_max = {};
        upper_min = {};
        usize = 0;
        lsize = 0;
    }
    
    void addNum(int num) {
        if(lower_max.size()-upper_min.size()<2) {
            lsize++;
            if (!upper_min.empty() && upper_min.top()<num){
                lower_max.push(upper_min.top());
                upper_min.pop();
                upper_min.push(num);
            }else{
                lower_max.push(num);
            }
        }
        else {
            usize++;
            if (lower_max.top()>num) {
                upper_min.push(lower_max.top());
                lower_max.pop();
                lower_max.push(num);
            }
            else{
                upper_min.push(num);
            }
        }
    }
    
    double findMedian() {
        if ((lower_max.size() + upper_min.size())%2){
            return lower_max.top();
        }
        double a = lower_max.top(); lower_max.pop();
        double b = lower_max.top();
        lower_max.push(a);
        return (a - (a-b)/2);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */