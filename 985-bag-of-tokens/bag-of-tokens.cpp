class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // make a multi set
        // agar power > token toh sabse chota element nikal aur power me se ghata de
        // else sabse bada token nikal uski power lele aur score kam karde

        multiset<int>s(tokens.begin(), tokens.end());
        int score =0;
        int ans =0;
        while(s.size()>0){
            auto start = s.begin();
            auto end = --s.end();
            // cout<<"start: "<<*start<<" "<<"end: "<<*end<<endl;
            if(power>=(*start)){
                power-=(*start);
                score++;
                ans = max(ans, score);
                s.erase(start);
            }
            else if(score>=1){
                power+=(*end);
                score--;
                s.erase(end);
            }
            else{
                break;
            }
        }
        return ans;
    }
};