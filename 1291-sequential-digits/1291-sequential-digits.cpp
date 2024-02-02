class Solution {
private:
    vector<int>preprocess(){
        vector<int>ans;
        
        int prev = 12;
        int dig = 2;

        while(prev<123456789){
            ans.push_back(prev);
            if(to_string(prev).back()=='9'){
                dig++;
                prev =0;
                for(int i=1; i<=dig; i++){
                    prev = prev*10+i;
                }
                continue;
            }
            string num_to_add = "";
            int len = to_string(prev).size();
            for(int i=0; i<len; i++){
                num_to_add.push_back('1');
            }

            
            prev+=stoi(num_to_add);

        }
        ans.push_back(prev);
        return ans;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
         vector<int>ans = preprocess();
         vector<int>ansf;
         for(auto it: ans){
             if(it>=low and it<=high){
                 ansf.push_back(it);
             }
         }
         return ansf;
    }
};