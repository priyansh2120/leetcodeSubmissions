class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string>mpp(wordList.begin(), wordList.end());
       queue<pair<string, int>>q;
       q.push({beginWord,1});

       while(!q.empty()){
           auto it = q.front();
           string curr = it.first;
           int ladder = it.second;
           q.pop();
           if(curr==endWord){
               return ladder;
           }
           if(mpp.find(curr)!=mpp.end()){
               mpp.erase(curr);
           }
           for(int i=0; i<curr.size(); i++){
               char ori = curr[i];
               for(char j ='a'; j<='z'; j++){
                   curr[i]=j;
                   if(mpp.find(curr)!=mpp.end()){
                       q.push({curr, ladder+1});
                   }
               }
               curr[i]=ori;
           }
       }
       return 0;
    }
};