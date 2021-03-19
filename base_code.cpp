#include<bits/stdc++.h>
using namespace std;

#define pb              push_back
#define sz(x)           (int)x.size()
#define f               first
#define s               second
#define all(x)          x.begin(), x.end()
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fr(i, a, b)     for(int i = a; i < b; ++i)
#define endl            '\n'
#define MOD             1000000007
#define ll              long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef ONLINE_JUDGE
#define debug(...)
#else
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#endif

#define int long long

void solve() {
        
}

int32_t main() {
        fast;
        int T = 1;
        // cin >> T;
        while(T--) {
                solve();
        }
}
