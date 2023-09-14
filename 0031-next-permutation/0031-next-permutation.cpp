class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        if(n==1){
            return;
        }
        int bpt = -1;
        for(int i=n-2; i>=0; i--){
            if(arr[i+1]>arr[i]){
                bpt =i;
                // cout<<bpt<<endl;
                break;
            }
        }
        if(bpt==-1 ){
            sort(arr.begin(), arr.end());
            return ;
        }
        
        // vector<int>ans=arr;
        
        int mini = 1e8;
        int ind =-1;
        for(int i=bpt+1; i<n; i++){
            if(arr[i]<mini and arr[i]>arr[bpt]){
                mini= arr[i];
                ind = i;
            }
        }
        // cout<<ind<<endl;
        cout<<arr[bpt]<<" "<<arr[ind]<<endl;
        swap(arr[bpt], arr[ind]);
        
        sort(arr.begin()+bpt+1, arr.end());
        
    }
};