class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // next greater element
       
        stack<pair<int,int>>st;
        int n = temperatures.size();
        vector<int>ans(n,0);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and temperatures[i]>=st.top().first){
                st.pop();
            }
            if(st.empty()){
                ans[i]=0;
            }
            else{
                ans[i]= st.top().second-i;
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};