
// intially choose hi and lo both are excluded (hi,lo)

int ternary_search(int hi,int lo){ // for increasing then decreasing 
    while(hi - lo > 2) {
        int mid = (lo + hi) >> 1;
        if(f(mid) < f(mid+1)) {
            lo = mid; // modify accordingly for other cases
        }
        else { 
            hi = mid+1;
        }
    }
    return (lo + hi)/2;
}

int ternary_search(int hi,int lo){ // for decreaing then increasing  
    while(hi - lo > 2) {
        int mid = (lo + hi) >> 1;
        if(f(mid) > f(mid+1)) {
            lo = mid; // modify accordingly for other cases
        }
        else { 
            hi = mid+1;
        }
    }
    return (lo + hi)/2;
}