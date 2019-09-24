
/* codeforces.com/problemset/problem/508/D 
    problem on Euler tour.

    euler tour - starting and ending on the same vertex wihout reusing any edge and visiting every vertex.

    Here we are using Hierholzer algo in which we travel each edge once and remove it, once we get to 
    the vertex we have no out edges from , we push it into the stack , this is the euler tour in reversed 
    order - (Just think it's very intiutive algorithm ;) )

    condition for euler tour 
    1)in degree == outdegree  ( for every vertex) 
    2)graph should be SCC (nodes which are connected) (*this is need not to be  valid for euler path)
    
    algo complexity - (O(E + V))

    *for undirected graphs - degree should be even for each vertex and should be connected.
    
    -- code written below is for euler path which can be modified for euler tour .
*/ 

// Write only proved sloutions

const int N = 100000;
std::vector<int> adj[N];
const int P = 97;
std::vector<int> inDeg(N,0),outDeg(N,0);
int val(char a,char b) {
        return (a-'0') + (b - '0')*P;
}

void add(string &s) {
        int a = val(s[0],s[1]);
        int b = val(s[1],s[2]);
        adj[a].pb(b);
        outDeg[a]++;;
        inDeg[b]++;
}
int n;
string f(int x) {
        int temp = x%P;
        string r = "";
        r += (char)('0' + temp);
        temp = x - temp;
        temp /= P;
        r += (char)('0' + temp);
        return r;
}
std::vector<int> path;

void dfs(int node) {
        while(adj[node].size()) {
                int temp = adj[node].back();
                adj[node].pop_back(); // removing each edge after traveling 
                dfs(temp);
        }
        path.pb(node); // each edge has been travelled now, pushing the vertex into stack
}

void solve() {
        cin >> n;
        set<string> hh;
        for(int i= 0; i < n; ++i) {
                string s;
                cin >> s;
                hh.insert(s);
                add(s);
        }  
        int st = -1;
        int count = 0;
        for(int i = 1; i< N; ++i) {
                if(adj[i].size() and st == -1) {
                        st = i;
                }
                if(outDeg[i] == inDeg[i]) {
                        continue;
                }
                else if(abs(inDeg[i] - outDeg[i])> 1) {
                        cout << "NO" << endl;
                        exit(0);
                }
                else if(outDeg[i] > inDeg[i]) {
                        count++;
                        st = i;
                }
                else if(inDeg[i] > outDeg[i]) {
                        count++;
                }
        }
        if(count != 0 and count != 2) {
                cout << "NO" << endl;
                exit(0);
        }
        dfs(st);
        reverse(all(path));
        string ans = "";
        debug_out(path);
        for(auto i:path) {
                if(ans.size() == 0) {
                        ans += f(i);
                }
                else {
                        string temp = f(i);
                        ans += temp[1];
                }
        }
        if(SZ(ans) == n+2) {
                cout << "YES" << endl;
                cout << ans << endl;
        }
        else {
                cout << "NO" << endl;
        }
}
