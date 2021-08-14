const int N = 1e5 + 2;
int pa[N], sz[N];

void make_set(int x) {
    pa[x] = x,  sz[x] = 1;
}

int find_set(int x) {
    if(pa[x] == x) return x;
    return pa[x] = find_set(pa[x]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(sz[b] < sz[a]) swap(a, b);
    sz[b] += sz[a];
    pa[a] = b;
} 
