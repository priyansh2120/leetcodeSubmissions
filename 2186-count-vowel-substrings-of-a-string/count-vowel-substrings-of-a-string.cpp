class Solution {
public:
    int countVowelSubstrings(string word) {
        vector<int>mini = {-1, -1, -1, -1, -1};

        int s=0, e=0;
        int ans = 0;
        while(e<word.size()){
            if(word[e]=='a'){
                mini[0]=e;
            }
            else if(word[e]=='e'){
                mini[1]=e;
            }
            else if(word[e]=='i'){
                mini[2]=e;
            }
            else if(word[e]=='o'){
                mini[3]=e;
            }
            else if(word[e]=='u'){
                mini[4]=e;
            }
            else{
                s=e+1;
            }
            ans+=max(0, *(min_element(mini.begin(), mini.end()))-s+1);
            e++;
        }
        return ans;
    }
};