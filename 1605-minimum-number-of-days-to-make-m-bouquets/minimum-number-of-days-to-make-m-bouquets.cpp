typedef long long int ll;
class Solution {
private:
    bool check(vector<int>& bloomDay, int m, int k, ll mid){
        int n = bloomDay.size();
        int chunks =0;
        int ele =0;
        
        for(int i=0; i<n; i++){
            if(bloomDay[i]<=mid){
                ele++;
            }
            else{
                ele=0;
            }
            if(ele>=k){
                chunks++;
                ele=0;
            }
        }
        return chunks>=m;
        
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        ll high = 1e18;
        ll low = 1;
        ll ans = 0;
        ll mini = m;
        mini*=k;
        if(bloomDay.size()<mini){
            return -1;
        }
        for(int i=0; i<100; i++){
            ll mid = (high+low)/2;
            if(check(bloomDay, m, k, mid)){
                ans = mid;
                high= mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};