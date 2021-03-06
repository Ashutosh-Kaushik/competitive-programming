#include<bits/stdc++.h>
using namespace std;
 
#define pb              push_back
#define SZ(x)           (int)x.size()
#define F               first
#define S               second
#define ALL(x)          x.begin(), x.end()
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i, a, b)    for(int i = a; i < b; ++i)
#define endl            '\n'
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef ONLINE_JUDGE
#define debug(...)
#else
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#endif
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9;
 
void solve() {

}
 
int main() {
        fast;
        int T = 1;
        cin >> T;
        while(T--) {
                solve();
        }
}