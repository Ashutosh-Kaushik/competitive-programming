// source https://codeforces.com/blog/entry/57292

const int N = 500+2;
int n;
int a[N],BIT[N];

// we store the sum last x elements in ith position where x is LSB of i 
// similarly we can travel while removing last bit to get the prefix sum in o(log(n))
// for updation we need to go to the larder index storing this element which can be found by adding LSB also
void update(int idx, int val) {
        int x = idx+1; // 1 based indexing
        while(x <= n) {
                BIT[x] += val;
                x += (x&(-x));
        }
}

int query(int idx) {
        int x = idx + 1;
        int ans = 0;
        while(x > 0) {
                ans += BIT[x];
                x -= (x&(-x)); // (x & -x gives the LSB of x which we romove)
        }
        return ans;
} 

void build() {
        memset(BIT,0,sizeof(BIT));
        for(int i = 0; i < n; ++i) {
                update(i,a[i]); // building in O(nlogn)
        }
}
// can be used 
void solve() {
        cin >> n;
        for(int i = 0; i < n; ++i) {
                cin >> a[i];
        }
        build();
        cout << query(4) - query(5) <<endl;
}
