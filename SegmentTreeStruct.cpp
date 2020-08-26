struct segmentTree {
        int n;
        vector<int> a, T, lazy;

        void init(int n) {
                this->n = n;
                a.assign(n, 0);
                T.assign(4 * n + 1, 0);
                lazy.assign(4 * n + 1, 0);
        }

        int combine(int a, int b) {
                return min(a, b);
        }

        void build(int node, int l, int r) {
                if(l == r) {
                        T[node] = a[l];
                        return;
                }
                int mid = (l + r) / 2;
                build(2 * node, l, mid);
                build(2 * node + 1, mid + 1, r);
                T[node] = combine(T[2 * node] + lazy[2 * node], T[2 * node + 1] + lazy[2 * node + 1]);
                return;
        }

        void prop(int node) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
                lazy[node] = 0;
        }
        int query(int node, int tl, int tr, int l, int r) {
                if(r < tl || tr < l) return LLONG_MAX;
                if(l <= tl && tr <= r) return T[node] + lazy[node];
                int mid = (tl + tr) /  2;
                prop(node);
                int leftmin = query(2 * node, tl, mid, l, r);
                int rightmin = query(2 * node + 1, mid+1, tr, l, r);
                T[node] = combine(T[2 * node] + lazy[2 * node], T[2 * node + 1] + lazy[2 * node + 1]);
                return combine(leftmin, rightmin);

        }
        int minimum(int l, int r) {
                return query(1, 0, n-1, l, r);
        }
        void update(int node, int tl, int tr, int l, int r, int val) {
                if(r < tl || tr < l) return;
                if(l <= tl && tr <= r) {
                        lazy[node] += val;
                        return;
                }
                prop(node);
                int mid = (tl + tr) / 2;
                update(2 * node, tl, mid, l, r, val);
                update(2 * node + 1, mid + 1, tr, l, r, val);
                T[node] = combine(T[2 * node] + lazy[2 * node], T[2 * node + 1] + lazy[2 * node + 1]);
        }
        void increment(int l, int r, int val) {
                update(1, 0, n-1, l, r, val);
        }
};
