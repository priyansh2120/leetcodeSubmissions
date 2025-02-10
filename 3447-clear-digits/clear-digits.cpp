class Solution {
public:
    string clearDigits(string s) {
        int i=0;
        while(s.size()>=0 and i<s.size()){
            if(s[i]>='0' and s[i]<='9'){
                for(int j=i-1; j>=0 and i>=1; j--){
                    if(s[j]>='a' and s[j]<='z'){
                        cout<<i<<' '<<j<<endl;
                        cout<<s<<endl;
                        s.erase(s.begin()+j);
                        s.erase(s.begin()+(i-1));
                        // cout<<i<<' '<<j<<endl;
                        i=0;
                    }
                    else{
                        i++;
                    }
                }
                
            }
            else{
                i++;
            }
            
            
        }
        return s;
    }
};