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

int32_t main()
{
        fast;
        int t = 1;
        // cin >> t;
        for(int i = 1; i <= t; ++i)
                solve();
        cerr << "Time taken: " << ((clock() * 1000) / CLOCKS_PER_SEC) << "ms\n";
}

int timer;
const int N = 1e5;
std::vector<int> tin(N), tout(N);
int lg = (int)log2(N);
std::vector<int> adj[N];
std::vector<std::vector<int> > up;

bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] and tout[u] >= tout[v];
}


void dfs(int node, int prev) {
        timer++;
        tin[node] = timer;
        up[node][0] = prev; 
        FOR(i,1,lg+1) {
                up[node][i] = up[up[node][i-1]][i-1];
        }
        for(auto i:adj[node] ){
                if(i == prev)
                        continue;
                dfs(i,node);
        }
        tout[node] = timer;
}

int lca(int u, int v) {
        if(is_ancestor(u,v))
                return u;
        if(is_ancestor(v,u))
                return v;
        REV(j,lg,0) {
                if(!is_ancestor(up[u][j], v)) {
                        u = up[u][j];
                }
        }
        return up[u][0];
}

void solve() {
        up.assign(N, std::vector<int> (lg+1));
        int n;
        cin >> n;
        FOR(i,1,n) {
                int a,b;
                cin >> a >> b;
                adj[a].pb(b);
                adj[b].pb(a);
        }
        dfs(1,1);
        cout << lca(3,4) << endl;
}