#define ll long long
ll powm(ll a,ll b, ll m = MOD) {
        ll ans=1; 
        while(b > 0){ 
                if((b & 1) == 1) 
                        ans =(ans * a) % m; 
                b >>= 1; 
                a = (a * a) % m; 
        } 
        return ans % m; 
}
ll inv_mod(ll a,ll m = MOD) {
        return powm(a,m-2,m);
}
ll ad(ll a, ll b, ll m = MOD) {
        a = a + b;
        if(a >= m) a -= m;
        return a;
}
ll sb(ll a, ll b, ll m = MOD) {
        a = a - b;
        if(a < 0) a += m;
        return a;
}
ll mul(ll a, ll b, ll m = MOD) {
        return (a * b) % m;
}
ll mdiv(ll a, ll b, ll m = MOD) {
        return mul(a, inv_mod(b));
}
