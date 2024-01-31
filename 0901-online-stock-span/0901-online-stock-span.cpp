class StockSpanner {
public:
    stack<pair<int, int>>st;
    int cnt = 0;
    StockSpanner() {
        st.push({1e5, 0});
    }
    
    int next(int price) {
        while(!st.empty() and st.top().first<=price){
            st.pop();
        }
        
        cnt++;
        int ans = cnt- st.top().second;
        st.push({price, cnt});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */