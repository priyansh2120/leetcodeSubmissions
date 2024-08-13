typedef long long int ll;
class Solution {
private:
    ll gcd(ll x, ll y) {
        return y == 0 ? x : gcd(y, x % y);
    }

    ll lcm(ll x, ll y) {
        return (x / gcd(x, y)) * y;
    }

    bool check(int n, int a, int b, ll mid) {
        ll divByA = mid / a;
        ll divByB = mid / b;
        ll divByBoth = mid / lcm(a, b);

        return (divByA + divByB - divByBoth) >= n;
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        ll high = 1e18;
        ll low = 1;
        ll ans = 0;
        const int MOD = 1e9 + 7;
        for(int i=0; i<60; i++){
            ll mid = (low+high)/2;
            if(check(n, a, b, mid)){
                ans= mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans%MOD;
    }
};