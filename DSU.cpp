const int N = 1e6+2;
int pa[N],sz[N];

void make_set(int x) {
    pa[x] = x;
    sz[x] = 1;
}

int find_set(int x) {
    if(pa[x] == x) {
        return x;
    }
    return pa[x] = find_set(pa[x]);
}

void union_set(int a,int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(rand()%2)
            swap(a,b);
        sz[a] += sz[b];
        pa[b] = a;
    }
}
void solve() {
    srand(time(0));
    for(int i = 1; i < N; ++i) make_set(i);
    // code goes here
}  
 


