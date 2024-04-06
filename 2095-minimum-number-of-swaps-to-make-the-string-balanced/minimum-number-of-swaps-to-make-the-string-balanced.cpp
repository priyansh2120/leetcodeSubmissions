class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='['){
                st.push(it);
            }
            else if(!st.empty()){
                st.pop();
            }

        }
        string temp; 
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        // cout<<temp<<endl;
        int ans = 0;
        for(int i=0; i<temp.size(); i++){
            if(temp[i]==temp[temp.size()-i-1]){
                ans++;
            }
        }
        return (ans+1)/2;
    }
};