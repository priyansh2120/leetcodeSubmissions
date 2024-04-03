class Solution {
private:
    bool isPrime(int n) {
      
        if (n <= 1)
            return false;

        
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;

        return true;
    }

public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int dr[] = {1, -1, 0, 0, -1, -1, 1, 1};
        int dc[] = {0, 0, 1, -1, -1, 1, -1, 1};
        map<int, int>mpp;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                
                
                for(int k =0; k<8; k++){
                    int sr = i;
                    int sc = j;
                    int num = 0;
                    while(sr>=0 and sr<mat.size() and sc>=0 and sc<mat[0].size()){
                        
                        num= num*10+mat[sr][sc];
                        sr+=dr[k];
                        sc+=dc[k];
                        
                        if(num>10 and isPrime(num)){
                            cout<<num<<endl;
                            mpp[num]++;
                        }
                    }
                }
            }
        }
        int ans = 0;
        int maxi = -1e5;
        for(auto it:mpp){
            if(it.second>=maxi){
                maxi = it.second; 
                ans = it.first;
            }
        }
        return (ans==0)?-1:ans;
    }
};