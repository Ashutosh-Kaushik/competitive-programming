#include<bits/stdc++.h>
using namespace std;

#define fi                      first
#define se                      second
#define pb                      push_back
#define endl                    '\n'
#define fast                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define FOR(i,a,b)              for(int i = a; i < b; ++i)

const int Max_node = 32* (1e6+2);
const int MSB = 32;

int trie[Max_node][2]; // total number of nodes possible, 2nd maxiumum branching of the node.
bool is_leaf[Max_node]; // stores true if current node is the leaf otherwise false
long long int cnt[Max_node];
int node = 0;

void init() {
	memset(trie,-1,sizeof(trie));
	memset(is_leaf,0,sizeof(is_leaf));
	memset(cnt,0,sizeof(cnt));
}

void insert(std::vector<int> &s) {
	int v = 0;
	cnt[v]++;
	FOR(i,0,32) {
		if(trie[v][s[i]] == -1) {
			node++;
			trie[v][s[i]] = node;	
		}
		v = trie[v][s[i]];
		cnt[v]++;
	}
	is_leaf[v] = true;
}

void tobinary(long long int no, std::vector<int> &v) { // converting a number number into 32 bit vector MSB at 0th and LSB at 31st0
	fill(v.begin(), v.end(), 0);
	for(int i = 31; i >= 0; i--) {
		int cur = (1 << (31-i));
		if((cur & no)) {
			v[i] = 1;
		}
	}
}

long long int subarrays(std::vector<int> &V,long long int k) { // problem specific funtion.
	int v = 0;
	long int cur = 0;
	long int sum = 0;
	FOR(i,0,32) {
		if(v == -1) {
			break;
		}
		if(V[i] == 0) {
			if(cur + (1ll << (31-i)) >= k) {
				if(trie[v][1] != -1) {
					sum += cnt[trie[v][1]];
				}
				v = trie[v][0]; 
			}
			else {
				v = trie[v][1];
				cur += (1ll << (31-i));
			}
		}
		else {
			if( cur + (1ll << (31-i)) >= k ) {
				if(trie[v][0] != -1) {
					sum += cnt[trie[v][0]];
				}
				v = trie[v][1];
				
			}
			else {
				v = trie[v][0];
				cur += (1ll << (31-i));
			}
		}
	}
	return sum;
}

int main () {
	init();
	int n;
	cin >> n;
	long long int k;
	cin >> k;
	std::vector<long long int> a(n);
	std::vector<int> v(32,0);
	long long int tot = 0;	
	insert(v);
	FOR(i,0,n) {
		cin >> a[i];
		if( i - 1 >= 0) {
			a[i] = (a[i-1]^a[i]);
		}
		tobinary(a[i],v);
		tot += subarrays(v,k);
		insert(v);
	}
	cout << tot << endl;
}

// random comment to test git