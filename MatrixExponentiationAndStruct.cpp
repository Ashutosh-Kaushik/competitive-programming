
#define int ll
const int MOD = 1e9 + 7;
const int N = 10;

struct Matrix {
	int arr[N][N];

	// setting all the elements to 0
	void reset() {
		memset(arr,0,sizeof(arr));
	}
	// making matirx's diagonal one
	void make_igen() {
		memset(arr,0,sizeof(arr));
		FOR(i,0,N) arr[i][i] = 1;
	}
	// adding the matrix
	Matrix add(Matrix &a, Matrix &b) {
		Matrix c;
		c.reset();
		FOR(i,0,N) {
			FOR(j,0,N) {
				c.arr[i][j] = a.arr[i][j] + b.arr[i][j];
			}
		}
		return c;
	}
	// multiplying the matrix
	Matrix mul(Matrix &a, Matrix &b) {
		Matrix c;
		FOR(i,0,N) {
			FOR(j,0,N) {
				int cur = 0;
				FOR(k,0,N) {
					int temp = a.arr[i][k] * b.arr[k][j];
					if(temp >= MOD)
						temp -= MOD;
					cur = (cur + temp);
					if(cur >= MOD)
						cur -= MOD;
				}
				c.arr[i][j] = cur;
			}
		}
		return c;
	}
	// For Printing the Matrix
	void Print(Matrix p) {
		FOR(i,0,N) {
	        	FOR(j,0,N) {
	        		cout << p.arr[i][j] <<  " ";
	        	}
	        	cout << endl;
        }
	}
};

Matrix pow(Matrix a, int b) { // matrix exponentiation
	Matrix res;
	res.make_igen();
	while(b) {
		if(b%2) {
			res = res.mul(res,a);
		}
		a = a.mul(a,a);
		b /= 2;
	} 
	return res;
}
