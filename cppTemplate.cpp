#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef IGM
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif

#define PI                      3.1415926535897932384626
#define int                     long long int
#define fi                      first
#define se                      second
#define pb                      push_back
#define endl                    '\n'
#define all(x)                  x.begin(),x.end()
#define pii                     pair<int,int>
#define fast                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZ(x)                   ((int)x.size())
#define ordered_set             tree <int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// find_by_order(x) ==> xth element in the set counting from 0
// order_of_key(x) ==> number of element strictly less than x

typedef long long ll;
typedef long double ld;

template<typename T> T pow(T a,T b, int m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
template<typename T> T InverseMod(T a,T m){return pow(a,m-2,m);}
template<typename T>int SquareDist(T a,T b){int x = abs(a.fi - b.fi),y = abs(a.se - b.se); return x*x + y*y;}
template<typename T> T pow2(T a,T b){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a); b/=2; a=(a*a); } return ans; }
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
 
// Write only proved sloutions



void solve() {
        
}


int32_t main()
{
        fast;
        int t = 1;
        // cin >> t;
        for(int i = 1; i <= t; ++i)
                solve();
        cerr << "Time taken: " << ((clock() * 1000) / CLOCKS_PER_SEC) << "ms\n";
}
