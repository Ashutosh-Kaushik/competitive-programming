
/*
	here we store the the sum of all 1,2,4,8... elements from ith index, so S[n][LOG2(max)]
	we will use the property 4 + 4 = 8, 8 + 8 = 16 and so on, you can think of 

*/

#define int ll
const int K = 62;
const int N = 1e5+5;
int lg[N];
int s[N][K];
int a[N];
int n;

void build() {
	FOR(i,0,n) {
		s[i][0] = a[i];
	}
	lg[1] = 0;
	FOR(i,2,N) {
		lg[i] = lg[i/2] + 1; // for range minimum query
	}
	FOR(j,1,K+1) {
		for(int i = 0; i + (1ll << j) <= n; ++i) {
			// storing sum of next 2^j elements starting from i, given we have calculated
			// for 2^(j-1)
			s[i][j] = min(s[i][j-1], s[i + (1ll << (j-1))][j-1]); // change
		}
	}
}

int RMQ(int l,int r) {

	int j = lg[r-l+1];
	return min(s[l][j],s[r - (1ll << j) + 1][j]); // change
}


int Query(int l,int r) {
	int ans = 0;
	REV(i,K,0) {
		if((1 << i) <= r - l + 1) {
			ans += s[l][i];
			l += (1 << i);
		}
	}
	return ans;
}


