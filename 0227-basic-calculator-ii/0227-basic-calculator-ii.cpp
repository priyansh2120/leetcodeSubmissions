class Solution {
private:
    int getPre(char op){
        if(op=='+' or op == '-'){
            return 0;
        }
        if(op == '/' or op=='*'){
            return 1;
        }
        return 0;
    } 
    bool isDig(char x){
        return (x>='0' and x<='9');
    }
public:
    int calculate(string s) {
        int ans = 0;
        stack<int>nums;
        stack<char>op;
        int i =0;
        while(i<s.size()){
            while(s[i]==' '){
                i++;
            }
            int num =0;
            bool check = false;
            if(isDig(s[i])){
                check = true;
                while(isDig(s[i])){
                    num= num*10+(s[i]-'0');
                    i++;
                }
                // i--;
            }
            while(s[i]==' '){
                i++;
            }
            
            if (check) nums.push(num);
            if(check) cout<<num<<endl;
                if(s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/')
                {
                    if(op.empty() or (getPre(s[i])>getPre(op.top()))){
                        op.push(s[i]);
                        cout<<s[i]<<endl;
                        i++;
                    }
                    else if(getPre(s[i])<=getPre(op.top())){
                        // string exp = "";
                        cout<<s[i]<<' '<<op.top()<<endl;
                        cout<<"cc"<<endl;
                        int n1 = nums.top();
                        nums.pop();
                        int n2 = nums.top();
                        nums.pop();
                        char opera = op.top();
                        op.pop();
                        int exp = 0;
                        if(opera=='+'){
                            exp = n1+n2;
                        }
                        else if(opera=='-'){
                            exp= n2-n1;
                        }
                        else if(opera=='*'){
                            exp = n2*n1;
                        }
                        else if(opera=='/'){
                            exp = n2/n1;
                        }
                        nums.push(exp);
                    }
            }
        }
        while(!op.empty()){
            int n1= nums.top();
            nums.pop();
            int n2 = nums.top();
            nums.pop();
            char opera = op.top();
            op.pop();
            int exp = 0;
                        if(opera=='+'){
                            exp = n1+n2;
                        }
                        else if(opera=='-'){
                            exp= n2-n1;
                        }
                        else if(opera=='*'){
                            exp = n2*n1;
                        }
                        else if(opera=='/'){
                            exp = n2/n1;
                        }
                        nums.push(exp);

        }
        return nums.top();
    }

};