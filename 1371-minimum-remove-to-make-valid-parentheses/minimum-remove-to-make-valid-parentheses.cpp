class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>>st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push({'(', i});
            }
            else if(s[i]==')'){
                if(st.empty()){
                    st.push({')', i});
                }
                else if(st.top().first=='('){
                    st.pop();
                }
                else if(st.top().first==')'){
                    st.push({')', i});
                }
            }
        }
        string ans;
        for(int i=s.size()-1; i>=0; i--){
            if(!st.empty() && i==st.top().second){
                st.pop();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};