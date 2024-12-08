class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int>mpp;
        for(auto it:arr){
            mpp[it]++;
        }
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==0){
                if(mpp[0]>1){
                    return true;
                }
            }
            else{
                if(mpp.count(arr[i]*2)>0){
                    return true;
                }
            }
            
        }
        return false;
    }
};