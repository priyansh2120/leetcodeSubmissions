class MedianFinder {
public:
    multiset<int>st;

    MedianFinder() {
    }
    
    void addNum(int num) {
        st.insert(num);
    }
    
    double findMedian() {
        int len = st.size();
        auto it = st.begin();
        if(len&1){
            advance(it, len / 2);
            return *it;
        }
        advance(it, len/2 -1);
        double ans = *it;
        it++;
        ans += *it;

        ans /= 2.0;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */