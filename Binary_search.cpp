

int search(int hi,int lo) {
    while(hi - lo > 1) {
        int mid = (lo + hi) >> 1;
        if(check(mid)) {
            hi = mid; // modify accordingly
        }
        else {
            lo = mid;
        }
    }
    return hi;
}