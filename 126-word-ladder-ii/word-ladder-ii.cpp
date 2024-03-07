class Solution {
private:
    void dfs(vector<string>&temp, string beginWord, string endWord){
        int n= beginWord.size();
        int currlvl = mpp[beginWord];
        if(beginWord==endWord){
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(),temp.end());

        }
        for(int i=0; i<n; i++){
            char original = beginWord[i];
            for(char ch='a'; ch<='z'; ch++){
                beginWord[i]=ch;
                if((mpp.find(beginWord)!=mpp.end()) and mpp[beginWord]+1==currlvl){
                    temp.push_back(beginWord);
                    dfs(temp,beginWord, endWord);
                    temp.pop_back();
                }
                beginWord[i]=original;
            }
        }

    }
public:
    vector<vector<string>>ans;
    map<string,int>mpp;
    
    queue<string>q;
    vector<string>temp;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>ust(wordList.begin(), wordList.end());
        q.push(beginWord);
        int level=1;
        mpp[beginWord]=level;
        ust.erase(beginWord);
        int len= beginWord.size();

        while(!q.empty()){
            string word= q.front();
            q.pop();
            if(word== endWord){
                break;
            }
            level =mpp[word];

            for(int i=0; i<len; i++){
                char original = word[i];
                for(char ch= 'a'; ch<='z'; ch++){
                    word[i]=ch;
                    if(ust.count(word)>0){
                        mpp[word]=level+1;
                        q.push(word);
                        ust.erase(word);
                    }
                    word[i]=original;
                }
            }

        }
        temp.push_back(endWord);
        dfs(temp, endWord, beginWord);

        return ans;
    }
};