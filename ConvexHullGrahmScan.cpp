#include<bits/stdc++.h>
using namespace std;

#define F                      first
#define S                      second
#define pb                      push_back
#define endl                    '\n'
#define all(x)                  x.begin(),x.end()
#define pii                     pair<int,int>
#define pll                     pair< long long int, long long int> 
#define fast                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZ(x)                   ((int)x.size())

#define FOR(i,a,b)              for(int i = a; i < b; ++i)
#define REV(i,a,b)              for(int i = a; i >= b; --i)
#define FORE(i,a,b)             for(int i = a; i <= b; ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve();

int main()
{
        fast;
        solve();
}

std::vector<pii> v;

pii gg;
bool cmp(pii a, pii b) { // sorting using polar angle;
	a.F -= gg.F;
	b.F -= gg.F;
	a.S -= gg.S;
	b.S -= gg.S;
	int p = a.F * b.S - a.S * b.F;
	int d1 = abs(a.F) + abs(a.S);
	int d2 = abs(b.F) + abs(b.S);
	if(p > 0) {
		return true;
	}
	else if(p == 0 and d1 < d2) {
		return true;
	}
	return false;
}

int check(pii a, pii b, pii c) {
	int x1 = b.F - a.F;
	int y1 = b.S - a.S;

	int x2 = c.F - a.F;
	int y2 = c.S - a.S;

	int p = x1*y2 - x2*y1;
	return p ;
}

void convexhull() {
	std::vector<pii> st;
	sort(all(v));

	st.pb(v[0]);
	gg = v[0];
	v.erase(v.begin());
	sort(all(v), &cmp);
	st.pb(v[0]);

	FOR(i,1,int(v.size())) {
		while(SZ(st) > 1 and check(st[SZ(st)-2], st.back(), v[i]) <= 0) {
			st.pop_back();
		}
		st.push_back(v[i]);			
	}
	cout << endl;
	for(auto i:st) {
		cout << i.F << " " << i.S << endl;
	}
}
 
void solve() {
        int n;
        cin >> n;
        FOR(i,0,n) {
        	int a,b;
        	cin >> a >> b;
        	v.pb({a,b});
        }
        convexhull();
}