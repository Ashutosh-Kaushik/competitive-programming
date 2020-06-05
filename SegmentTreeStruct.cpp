const int N = 1e5+4 ;//  length of the intial array and is used in the segtree;
std::vector<int> a(N,0);
const int INF = INT_MAX;

struct SegTree // just to use multiple segment tree without changing code;
{
        std::vector<int> t;
        std::vector<int> lazy;
        std::vector<bool> updateNeeded;
        SegTree() {
                t.assign(4*N,0);
                lazy.assign(4*N+5,0);
                updateNeeded.assign(4*N+5,0);
        }

        void combine(int &cur, int &l, int &r) { //  update the combine function
                cur = min(l,r);
        }

        void passDown(int node, int val, int tl, int tr) {
                t[node] = val;
                if(tl != tr) {
                        updateNeeded[2*node] = 1;
                        updateNeeded[2*node+1] = 1;
                        lazy[2*node] = val;
                        lazy[2*node + 1] = val;
                }
                updateNeeded[node] = 0;
        }
        // build()
        void build(int node = 1, int l = 0, int r = N-1) {
                if(l == r) {
                        t[node] = a[l];
                        return;
                }
                int mid = (l + r) / 2;
                build(2*node, l, mid);
                build(2*node+1, mid+1,r);
                combine(t[node], t[2*node], t[2*node+1]);
        }

        // query(l,r); 0 based indexing
        int query(int l, int r, int node = 1, int tl = 0, int tr = N-1) {
                
                if(updateNeeded[node]) {
                        passDown(node,lazy[node], tl, tr);
                }

                if(tl > tr or l > r or r < tl or tr < l) {
                        return INF; // change; right now we are calculating minimum so return INF
                }

                if(tl >= l and tr <= r) {
                        return t[node];
                }

                int mid = (tl + tr) / 2;
                int p = query(l, r, 2*node, tl, mid);
                int q =  query(l, r, 2*node+1, mid+1,tr);
                int ret;
                combine(ret, p, q);
                return ret;

        }

        // update(l,r,val); 0 based indexing
        void update(int l, int r, int val, int node = 1, int tl = 0, int tr = N-1) {
                
                if(updateNeeded[node]) {
                        passDown(node, val, tl, tr);
                }

                if(tl > tr or l > r or r < tl or tr < l) {
                        return;
                }
                if(tl >= l and tr <= r) {
                        passDown(node, val, tl, tr);
                        return;
                }
                int mid = (tl + tr) / 2;
                update(l,r,val,2*node,tl,mid);
                update(l,r,val,2*node+1,mid+1,tr);
                combine(t[node], t[2*node], t[2*node+1]);
        }

        //pquery(pos);  0 based indxing

        int pquery(int pos, int node = 1, int tl = 0, int tr = N-1) {
                if(updateNeeded[node]) {
                        passDown(node,lazy[node], tl, tr);
                }

                if(pos < tl or pos > tr or tl > tr) {
                        return INF; // change; right now we are calculating minimum so return INF
                }

                

                if(tl == tr) {
                        return t[node];
                }

                int mid = (tl + tr) / 2;
                if(mid >= pos)
                        return pquery(pos, 2*node, tl, mid);
                else
                        return pquery(pos, 2*node+1, mid+1,tr);

        }
        // pupdate(pos, val)
        void pupdate(int pos, int val, int node = 1, int tl = 0, int tr = N-1) {
                
                if(updateNeeded[node]) {
                        passDown(node, val, tl, tr);
                }

                if(pos < tl or pos > tr) {
                        return;
                }
                if(tl == tr) {
                        passDown(node, val, tl, tr);
                        return;
                }
                int mid = (tl + tr) / 2;
                if(mid >= pos)
                        pupdate(pos,val,2*node,tl,mid);
                else
                        pupdate(pos, val,2*node+1,mid+1,tr);
                combine(t[node], t[2*node], t[2*node+1]);
        }
        
};
