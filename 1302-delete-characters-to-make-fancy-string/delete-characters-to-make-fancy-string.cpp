class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if(n<=2){
            return s;
        }
        string ans ="";
        ans.push_back(s[0]);
        ans.push_back(s[1]);
        int j=1;
        for(int i=2; i<n; i++){
            if(s[i]==ans[j] and s[i]==ans[j-1]){
                // cout<<"here"<<endl;
                continue;
            }
            ans.push_back(s[i]);
            j++;
            
        }
        return ans;
    }
};