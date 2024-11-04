class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int i=0,n=word.size();
        while(i<n){
            int count=1;
            int j=i+1;
            while(j<n && word[j]==word[i]){
                j++;
                count++;
                if(count==9) break;
            }
            comp+=to_string(count);
            comp+=word[i];
            i=j;
        }
        return comp;
    }
};