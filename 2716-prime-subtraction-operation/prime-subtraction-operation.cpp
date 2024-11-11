class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int>prime;
        for(int i=2; i<1000; i++){
            bool flag = true;
            for(int j=2; j*j<=i; j++){
                if(i%j==0){
                    flag=false; 
                    break;
                }
            }
            if(flag){
                prime.push_back(i);
            }
        }
        if(nums[0]>2){
            int lb = *(lower_bound(prime.begin(),prime.end(), nums[0])-1);
            nums[0]-=lb;
        }
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i]- nums[i-1]<=0){
                return false;
            }

            if(nums[i]-nums[i-1]>2){
                int lb = *(lower_bound(prime.begin(),prime.end(), nums[i]-nums[i-1])-1);
                nums[i]-=lb;
            }
            

        }
        
        return true;
    }
};