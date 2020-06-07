struct Hash {
        int n;
        std::vector<int> h;
        std::vector<int> expo;
        int p,m;
        void cal(int N, int P, int M, string &s) {     
                n = N; p = P; m = M;
                h.assign(n+1,0);
                expo.assign(n+1,0);
                expo[0] = 1;
                h[0] = 0;
                FOR(i,1,n+1) {
                        expo[i] = (expo[i-1] * p) % m;
                        h[i] = add(mul(h[i-1],p,m),s[i-1]-'0'+1,mod);
                        // We are using a different hasing function
                        // hash(k+1) = hash(k)*prime + s[k+1],hash value for string of length 3 is (s[0]*p^2 + s[1]*p + s[2])
                        // for length 4 hash value = s[0]*p^4 + s[1]*p^3 + s[2]*p^2 + s[1]*p + s[0]
                }
        }

        // hash value of substring starting at index i and having length len
        // hash[i+len] - hash[i] * (prime ^ len) == hash[j + len] - hash[j] * (prime ^len) (IMP)
        //https://codeforces.com/blog/entry/60445
        int HashVal(int i, int len) {
                
                return sub(h[i+len], mul(h[i],expo[len],m),m);
        }

};