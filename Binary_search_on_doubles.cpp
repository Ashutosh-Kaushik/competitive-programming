


long double search_double(long double hi,long double lo) {
    long double eps = 1.00000000000000/1e9;
    while(hi - lo > eps) {
        long double mid = (lo + hi) / 2;
        if(check(mid)) {
            lo = mid; // modify accordingly
        }
        else {
            hi = mid;
        }
    }
    return hi;
}