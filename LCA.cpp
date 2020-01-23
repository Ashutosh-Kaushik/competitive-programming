
// lca using sparse table for RMQ, here we store the euler tour from tree, then we get the node the 
// with the minimum height between the first occurence of the two. 

// https://codeforces.com/problemset/problem/191/C
// problem is a bit different but concpets are used 

#include<bits/stdc++.h>
using namespace std;

#define fi                      first
#define se                      second
#define pb                      push_back
#define endl                    '\n'
#define all(x)                  x.begin(),x.end()
#define pii                     pair<int,int>
#define pll                     pair< long long int, long long int> 
#define fast                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZ(x)                   ((int)x.size())

#define FOR(i,a,b)              for(int i = a; i < b; ++i)
#define REV(i,a,b)              for(int i = a; i >= b; --i)
#define FORE(i,a,b)             for(int i = a; i <= b; ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve();



#define int ll
const int K = 62;
const int N = 2e5+5;
int lg[N];
int s[N][K];
int a[N]; 
int euler_Tour[2*N + 10];
int Pa[N], dp[N];
int n; // length of array we are building 
int p = 0;
std::vector<int> First(N), hgt(N);
std::vector<int> adj[N];


void dfs(int node, int prev, int h) {
        euler_Tour[p++] = node;
        // cout << p-1 << " " << node << endl;
        hgt[node] = h;
        for(auto i:adj[node]) {
                if(i != prev) {
                        dfs(i,node,h+1);
                        euler_Tour[p++] = node;
                        // cout << p-1 << " " << node << endl;
                        Pa[i] = node;
                }
        }
}

void dfs2(int node, int prev) {
        for(auto i:adj[node]) {
                if(i != prev) {
                        dfs2(i,node);
                        dp[node] += dp[i];
                }
        }
}
void build() {
        FOR(i,0,n) {
                s[i][0] = i;
        }
        lg[1] = 0;
        FOR(i,2,N) {
                lg[i] = lg[i/2] + 1; // for range minimum query
        }
        FOR(j,1,K+1) {
                for(int i = 0; i + (1ll << j) <= n; ++i) {
                        // storing sum of next 2^j elements starting from i, given we have calculated
                        // for 2^(j-1)
                        s[i][j] = a[s[i][j-1]] < a[s[i + (1ll << (j-1))][j-1]] ? s[i][j-1] : s[i + (1ll << (j-1))][j-1]; // change
                }
        }
}

int RMQ(int l,int r) {

        int j = lg[r-l+1];
        return a[s[l][j]] < a[s[r - (1ll << (j)) + 1][j]] ? s[l][j] : s[r - (1ll << (j)) + 1][j]; // change
}


int Query(int l,int r) {
        int ans = l;
        REV(j,K,0) {
                if((1ll << j) <= r - l + 1) {
                        if(a[ans] > a[s[l][j]]) {
                                ans = s[l][j];
                        }
                        l += (1 << j);
                }
        }
        return ans;
}


int32_t main()
{
        fast;
        int t = 1;
        // cin >> t;
        for(int i = 1; i <= t; ++i)
                solve();
        cerr << "Time taken: " << ((clock() * 1000) / CLOCKS_PER_SEC) << "ms\n";
}

void solve() {
        int no;
        cin >> no;
        std::vector<pii> v;
        FOR(i,0,no-1) {
                int A,b;
                cin >> A >> b;
                v.pb({A,b});
                adj[A].pb(b);
                adj[b].pb(A);
        }
        dfs(1,1,0);
        Pa[1] = 1;
        n = p;
        REV(i,p-1,0) {
                First[euler_Tour[i]] = i;
                a[i] = hgt[euler_Tour[i]];
        }
        build();
        // cout << a[1] << endl;
        int k;
        cin >> k;
        memset(dp,0,sizeof(0));
        // cout << endl;
        // FOR(i,1,no+1) {
        //         cout << First[i] << " " << euler_Tour[First[i]] << endl;
        // }
        FOR(i,0,k) {
                int A,B;
                cin >> A >> B;
                v.pb({A,B});
                int node = euler_Tour[Query(min(First[A],First[B]), max(First[A],First[B]))];
                // cout << A << " " << B << " " <<node << " " << First[A] << " " << First[B] << endl;
                dp[A]++;
                dp[B]++;
                dp[node] -= 2;
        }
        
        dfs2(1,1);
        // FOR(i,1,no+1) {
                // cout << i << " " << dp[i] << endl;
        // }
        FOR(i,0,no-1) { 
                int A = v[i].fi, B = v[i].se;
                if(Pa[A] != B)
                        swap(A,B);
                cout << dp[A] << " "; 
        }
        cout << endl;
}