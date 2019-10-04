// source https://codeforces.com/blog/entry/15729

const int N = 500+2;
int t[4*N];
int lazy[4*N];
int a[N];
int n; 

void init() {
        memset(lazy,0,sizeof(lazy));
}

void upd(int node, int l, int r, int x) {
        lazy[node] += x;
        t[node] += (r - l + 1) * x;
        return;
}

void passDown(int node, int l, int r) { 
        int mid = (l + r) / 2;
        upd(2 * node, l , mid, lazy[node]);
        upd(2 * node + 1, mid + 1 , r, lazy[node]);
        lazy[node] = 0;
}

void build(int node = 1,int tl = 0,int tr = n - 1) {
        if(tl > tr) {
                return;
        }
        if(tl == tr) {
                t[node] = a[tl];
                return;
        }
        int mid = (tl + tr) / 2;
        build(2 * node, tl, mid);
        build(2 * node + 1, mid + 1, tr);
        t[node] = t[2 * node] + t[2 * node + 1];
}

void updateRange(int l, int r,int val, int node = 1, int tl = 0, int tr = n-1) {
        if(r < l or l > tr or tl > r or tl > tr) {
                return;
        }
        if(l <= tl and tr <= r) {
                upd(node,l,r,val);
                return;
        }
        passDown(node, tl, tr);
        int mid = (tl + tr) / 2;
        updateRange(l, r, val, 2 * node, tl , mid);
        updateRange(l, r, val, 2 * node + 1, mid+1, tr);
        t[node] = t[2 * node] + t[2 * node + 1];
}

int queryRange(int l, int r,int node = 1, int tl = 0, int tr = n-1) {
        if (r < l or tr < tl or l > tr or tl > r) {
                return 0;
        }
        if(l <= tl and tr <= r) {
                return t[node];
        }
        passDown(node,tl,tr); 
        int mid = (tl + tr) / 2;
        return  (queryRange(l, r, 2 * node, tl, mid) + queryRange(l, r, 2 * node + 1, mid+1 , tr));
}

// updateRange(l,r,val) queryRange(l,r);

void solve() {
        cin >> n;
        for(int i = 0; i < n; ++i) {
                cin >> a[i];
        }
        init();
        build();
        updateRange(0,2,1);
        cout << queryRange(1,n-1) <<endl;
}
