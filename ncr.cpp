
const int mod = 1e9+7;
const int N = 1001;
int ncr[N][N];

void f() {
    fr(i,0,N-1) {
        fr(j,0,N-1) {
            if(j == 0) {
                ncr[i][j] = 1;
                continue;
            }
            else if(i == 0) {
                ncr[i][j] = 0;
                continue;
            }
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%mod;
        }
    }
}

void solve() {
    f();
    //code goes here
}  
 