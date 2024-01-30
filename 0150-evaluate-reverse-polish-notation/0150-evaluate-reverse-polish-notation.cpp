class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n = tokens.size();
        int ans = 0;
        for(int i= 0; i<n; i++){
            if(tokens[i]!="+" and tokens[i]!="-" and tokens[i]!="*" and tokens[i]!="/"){
                st.push(stoi(tokens[i]));
            }
            else{
                int op1= st.top();
                st.pop();
                int op2= st.top();
                st.pop();
                if(tokens[i]=="+"){
                    int op3 = op1+op2;
                    st.push(op3);
                }
                else if(tokens[i]=="-"){
                    int op3 = op2-op1;
                    st.push(op3);
                }
                else if(tokens[i]=="*"){
                    int op3 = op2*op1;
                    st.push(op3);
                }
                else if(tokens[i]=="/"){
                    int op3 = op2/op1;
                    st.push(op3);
                }
            }

        }
        return st.top();
    }
};