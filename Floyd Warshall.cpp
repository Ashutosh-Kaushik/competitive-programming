
const int N = 100+2;
int d[N][N];

void FloydWarshall() {
	fr(k,1,N) { // minimum distance between node using first k nodes only
		fr(i,1,N) {
			fr(j,1,N) {
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}