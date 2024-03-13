class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ocnt = 0;
        for(auto it:s){
            if(it=='1'){
                ocnt++;
            }
        }
        string ans ="";
        for(int i=0; i<ocnt-1; i++){
            ans.push_back('1');
        }
        for(int i=0; i<s.size()-ocnt; i++){
            ans.push_back('0');
        }
        ans.push_back('1');
        return ans;
    }
};